/*
Trees can be implemented using:
    1. dynamically created nodes
    2. arrays:
      for arrays node at index i:
        left child  = 2i + 1
        right child  = 2i + 2
        NOTE: giving that we traverse level wise.
*/


#include<stdio.h>
#include<stdlib.h>
#include "basic_operations.h"
// declaring all the static functions needed for a BST.
static void Init();
// static unsigned char isEmpty();
static void insert_node(long data);
/*------------------------------------------------------------------*/

static void Init(){
  struct Tree *root = (struct Tree*)malloc(sizeof(struct Tree)) ;
  root = NULL;
  return;
}
static void insert_node(long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  root = new_node;
  // printf("Root data is: %d \n", root->data);
}

int main(){
  Init();
  insert_node(10);
  printf("Hello");
  return 0;
}
