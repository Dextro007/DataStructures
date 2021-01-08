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

struct Graph{
  struct verticesHead *head;
};



int main(){
  return 0;
}
