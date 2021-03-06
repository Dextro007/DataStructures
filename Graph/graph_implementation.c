/*
In this program I am trying to implement graph using Adjacency list.
*/

#include<stdio.h>
#include<stdlib.h>
// all the adjacent vertices as linked lists
/***************************data types****************************/
struct adj_vertices{
  long linked_vertex;
  struct adj_vertices *next;
};

struct verticesHead{
  struct adj_vertices *head;
};

struct graph{
  long vertices;
  struct verticesHead *v_array;
};

/*---------------------------------------------------------------*/

struct adj_vertices *create_new_node(long data){
  struct adj_vertices *new_node = (struct adj_vertices*)malloc(sizeof(struct adj_vertices));
  new_node->linked_vertex = data;
  new_node->next = NULL;
  return new_node;
}
/*
Here we implement undirected graph
*/
void add_linked_vertex(struct graph *graph, long source, long destination){
  struct adj_vertices *adjacent_vertex = create_new_node(destination);
  adjacent_vertex->next = graph->v_array[source].head;
  graph->v_array[source].head = adjacent_vertex;
  // since the graph is undirected, add the same from dest to source
  struct adj_vertices *adjacent_vertex2 = create_new_node(source);
  adjacent_vertex2->next = graph->v_array[destination].head;                     // notice the use of -> and .
  graph->v_array[destination].head = adjacent_vertex2;
}

struct graph* createGraph(long Vertices){
  struct graph *new_graph  = (struct graph*)malloc(sizeof(struct graph));
  new_graph->vertices = Vertices;
  new_graph->v_array = (struct verticesHead*)malloc(Vertices * sizeof(struct verticesHead));
  for(int i = 0; i< new_graph->vertices; i++){
    new_graph->v_array[i].head = NULL;
  }
  return new_graph;
}

void print_graph(struct graph *graph){
  long v;
  struct adj_vertices *traverse = NULL;
  for(v=0; v< graph->vertices; v++){
    traverse = graph->v_array[v].head;
    // while we have a non NULL traversal value
    printf("Adjacent vertices to %ld is\n (%ld)", v,v);
    while(traverse){
      printf("->(%ld)", traverse->linked_vertex);
      traverse = traverse->next;
    }
    printf("\n");
  }
}

int main(){
  long Vertices = 6;
  struct graph *g1 = createGraph(Vertices);
  add_linked_vertex(g1, 0,1);
  add_linked_vertex(g1, 0,4);
  add_linked_vertex(g1, 1,4);
  add_linked_vertex(g1, 1,2);
  add_linked_vertex(g1, 1,3);
  add_linked_vertex(g1, 2,3);
  add_linked_vertex(g1, 3,4);
  print_graph(g1);
  return 0;
}
