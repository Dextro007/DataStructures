/*
Aim : delete the required node
*/
#include<stdio.h>
#include<stdlib.h>

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
//*****************************************************
static struct Tree* create_node(long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}


int main(){
  root = NULL;

  return 0;
}
