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
#if DISABLE
static unsigned char isEmpty();
#endif
static struct Tree* create_node(long data);
static struct Tree* insert(struct Tree *root, long data);
static void print2Dtree(struct Tree *root, unsigned long space);
/*------------------------------------------------------------------*/

struct Tree *root;
#if DISABLE
static unsigned char isEmpty(){
  return root==NULL;
}
#endif
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
  return root;
}

unsigned char search(struct Tree* root, long data){
  if(root == NULL)
    return False;
  else if(root->data == data){
    return True;
  }
  else if(data < root->data){
    return search(root->left, data);
  }
  else
    return search(root->right, data);
}

static void print2Dtree(struct Tree* root, unsigned long space){
  if(root == NULL){
    return;
  }
  unsigned long i;
  space += COUNT;

  print2Dtree(root->right, space);
  printf("\n");
  for(i = (unsigned long)COUNT; i<space; i++){
    printf(" ");
  }
  printf("%d\n", root->data);

  print2Dtree(root->left, space);
}
// function to find and return the height of
/*
ALGO:
1. If tree is empty then return 0
2. Else
     (a) Get the maximum height of left subtree recursively  i.e.,
          call calc_height( root->left_subtree)
     (a) Get the max height of right subtree recursively  i.e.,
          call calc_height( root->right_subtree)
     (c) Get the max of maximum heights of left and right
          subtrees and add 1 to it for the current node.
         calc_height = max(max height of left subtree,
                             max height of right subtree)
                             + 1
     (d) Return max
*/
unsigned long calc_height(struct Tree *root){
  if(root == NULL){
    return 0;
  }
  unsigned long lheight, rheight;
  lheight = calc_height(root->left);
  rheight = calc_height(root->right);

  if(lheight>rheight){
    return (lheight+1);
  }
  else
    return (rheight + 1);
}

int main(){
  // initializing the Root
  Init();
  root  = insert(root, 10);
  root = insert(root, 8);
  root = insert(root, 15);
  root = insert(root, 12);
  root = insert(root, 11);
  print2Dtree(root, 5);
  printf("height of the tree is: %lu\n", calc_height(root));
  //printf("searching 15: %d", search(root, 15));
  // printf("the value in root is: %d \n", root->data);

  return 0;
}
