#include<stdio.h>
#include<stdlib.h>
struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};
struct Tree *root;
//*********************************Functions**********************
static struct Tree* create_node(struct Tree *root, long data);
static struct Tree* insert_node(struct Tree *root, long data);
static long find_min(struct Tree *root);
static long find_max(struct Tree *root);
//--------------------------*****************---------------------

static struct Tree* create_node(struct Tree *root, long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->left  = NULL;
  new_node->right = NULL;
  new_node->data =  data;
  return new_node;
}

int main(){
  root = NULL;
  // insert_node()
  return 0;
}
