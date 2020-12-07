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
static unsigned char isEmpty();
static struct Tree* create_node(long data);
static struct Tree* insert(struct Tree *root, long data);
/*------------------------------------------------------------------*/

struct Tree *root;
static unsigned char isEmpty(){
  return root==NULL;
}

static void Init(){
  root = NULL;
  return;
}
// here  we try to create a tree node.
static struct Tree* create_node(long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;

  // printf("Root data is: %d \n", root->data);
}
// compare the data and then store the data acc. BST
static struct Tree* insert(struct Tree* root, long data){
  if(root == NULL){
     root = create_node(data);
     return root;
  }
  else if(data <= root->data){
    root->left = insert(root->left,data);
  }
  else{
    root->right = insert(root->right, data);
  }
}

int main(){
  // initializing the Root
  Init();
  // printf("the value in root is: %d \n", root->data);
  return 0;
}
