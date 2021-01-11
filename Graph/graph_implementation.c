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
  //add_linked_vertex(graph, destination, source)

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


int main(){
  return 0;
}
