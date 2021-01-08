/*
In this program I am trying to implement graph using Adjacency list.
*/

#include<stdio.h>
#include<stdlib.h>
// all the adjacent vertices as linked lists
struct adjVertices{
  long data;
  struct adjVertices *next;
};

struct verticesHead{
  struct adjVertices *head;
};

struct graph{
  long vertice;
  struct verticesHead *head;
};

struct graph* createGraph(long vertices){
  struct graph *new_graph  = (struct graph*)malloc(sizeof(struct graph));
  
}

int main(){
  return 0;
}
