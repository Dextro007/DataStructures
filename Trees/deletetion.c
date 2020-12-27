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
static struct Tree* minNode(struct Tree* root);
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

static struct Tree* search(struct Tree* root, long data){
  if(root == NULL)
    return NULL;
  else if(root->data == data){
    return root;
  }
  else if(data < root->data){
    root = search(root->left, data);
  }
  else{
    root = search(root->right, data);
  }
  return root;
}

static struct Tree* minNode(struct Tree *root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

static void delete_node(long data){
  struct Tree *node = search(root, data);
  if(node == NULL){
    printf("No such node exist");
    return;
  }
  else{
    // if the node has no child
    if(node->left == NULL && node->right == NULL){
      free(node);
    }else if(node->left != NULL && node->right == NULL){
      struct Tree *temp = node->left;
      node = temp;
      free(temp);
    }else if(node->right != NULL && node->left == NULL){
      struct Tree *temp = node->right;
      node = node->right;
      free(temp);
    }else{
      struct Tree* temp = minNode(node->right);
      long data = temp->data;
      delete_node(data);
      node->data = data;
    }
  }
  return;
}

int main(){
  root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 70);
  root = insert_node(root, 20);
  root = insert_node(root, 60);
  root = insert_node(root, 40);
  root = insert_node(root, 80);
  print2Dtree();
  return 0;
}
