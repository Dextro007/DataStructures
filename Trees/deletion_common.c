/*
Aim : delete the required node
*/
#include<stdio.h>
#include<stdlib.h>
#define COUNT 20

struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};
struct Tree *root;
//-----------------------FUNCTIONS-----------------------
static struct Tree* create_node(long data);
static struct Tree* insert_node(struct Tree* root, long data);
// static struct Tree* search(struct Tree* root, long data);
static struct Tree* delete_node(struct Tree *root, long data);
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

static struct Tree* insert_node(struct Tree *root, long data){
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
  printf("\n");
  for(unsigned long i = COUNT; i< space ; i++){
    printf(" ");
  }
  // after right comes the parent node
  printf("%ld", root->data);
  // after right print left
  print2Dtree(root->left, space);
}

static struct Tree* minNode(struct Tree *root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

static struct Tree* delete_node(struct Tree *root, long data){
  if(root == NULL){
    return root;
  }else if(data < root->data){
    root->left  = delete_node(root->left, data);
  }else if(data > root->data){
    root->right = delete_node(root->right, data);
  }
  else{
    if(root->left == NULL && root->right == NULL){
      root = NULL;
      return root;
    }
    else if(root->right == NULL){
      struct Tree *temp =  root->left;
      free(root);
      return temp;
    }
    else if(root->left == NULL){
      struct Tree *temp = root->right;
      free(root);
      return temp;
    }
    else{
      struct Tree *temp = minNode(root->right);
      long data = temp->data;
      root = delete_node(root,data);
      root->data = data;
    }

  }
  return root;
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
  print2Dtree(root, 5);
  printf("\n-------------***------------\n");
  root = delete_node(root,50);
  print2Dtree(root, 5);
  printf("\n");
  return 0;
}
