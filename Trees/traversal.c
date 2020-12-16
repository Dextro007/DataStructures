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
static struct Tree* insert_node(struct Tree *root , long data);
static void inorder(struct Tree* root);
static void preorder(struct Tree* root);
static void postorder(struct Tree* root);
//********************--------END-----------**********************

static struct Tree* create_node(long data){
  struct Tree* new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

static struct Tree* insert_node(struct Tree* root, long data){
  if(root == NULL){
    root = create_node(data);
    return root;
  }
  else if(data <= root->data){
    root->left = insert_node(root->left, data);
  }
  else{
    root->right  = insert_node(root->right, data);
  }
  return root;
}

static void inorder(struct Tree* root){
  if(root == NULL)
    return;
  // traversing the left nodes
  inorder(root->left);
  printf("%ld\t", root->data);
  // trsaversing the right nodes
  inorder(root->right);
  return;
}

static void preorder(struct Tree *root){
  if(root == NULL){
    return;
  }
  printf("%ld\t", root->data);
  preorder(root->left);
  preorder(root->right);
  return;
}

static void postorder(struct Tree *root){
  if(root == NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%ld\t", root->data);
  return;
}

int main(){
  root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 12);
  root = insert_node(root, 8);
  root = insert_node(root, 13);
  root = insert_node(root, 7);
  root = insert_node(root, 11);
  root = insert_node(root, 9);
  printf("Inorder: ");
  inorder(root);
  printf("\n");
  printf("Preorder: ");
  preorder(root);
  printf("\n");
  printf("Postorder: ");
  postorder(root);
  printf("\n");

  return 0;
}
