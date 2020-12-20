/*
Aim : delete the required node
*/
#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};
struct Tree *root;
//-----------------------FUNCTIONS-----------------------
static struct Tree* create_node(long data);
static struct Tree* insert_node(struct Tree* root, long data);
static struct Tree* search(struct Tree* root, long data);
static void delete_node(long data);
void print2Dtree(struct Tree *root, unsigned long space);
//*****************************************************
static struct Tree* create_node(long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

static Tree* insert_node(struct Tree *root, long data){
  if(root == NULL){
    root = create_node(data);
    return root;
  }else if(data <= root->data){
    root->left = insert_node(root->left, data);
  }
  else{
    root->right = insert_node(root->right, data);
  }
  return root;
}
void print2Dtree(struct Tree *root, unsigned long space){
  if(root == NULL){
    return;
  }
  space += COUNT;
  // right most element are to be printed 1st
  print2Dtree(root->right, space);
  for(unsigned long i = COUNT; i< space ; i++){
    printf(" ");
  }
  // after right comes the parent node
  printf("%ld", root->data);
  // after right print left
  print2Dtree(root->left, space);
}

int main(){
  root = NULL;

  return 0;
}
