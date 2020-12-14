#include<stdio.h>
#include<stdlib.h>

struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};

struct Tree *root;
//****************************--functions---**********************
static struct Tree* create_node(long data);
static struct Tree* insert_node(struct Tree*, long data);
static void inorder(struct Tree* root);
static void preorder(struct Tree* root);
static void postorder(struct Tree* root);
//********************--------END-----------**********************

static struct Tree* create_node(long data){
  struct Tree* new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
}

static struct Tree* insert_node(struct Tree*, long data){
  if(root == NULL){
    root = create_node(data);
    return root;
  }
  if(data <= root->data){
    root = insert_node(root->left, data);
  }
  else{
    root  = insert_node(root->right, data);
  }
  return root;
}

void inorder(struct Tree* root){
  if(root == NULL)
    return;
  inorder(root->left);
  printf("%ld\t", root->data);
  inorder(root->right);
  return;
}
int main(){

  return 0;
}
