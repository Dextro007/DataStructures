#include<stdio.h>
#include<stdlib.h>
struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};
struct Tree *root;
//*********************************Functions**********************
static struct Tree* create_node( long data);
static struct Tree* insert_node(struct Tree *root, long data);
static long find_min(struct Tree *root);
static long find_max(struct Tree *root);
//--------------------------*****************---------------------

static struct Tree* create_node(long data){
  struct Tree *new_node = (struct Tree*)malloc(sizeof(struct Tree));
  new_node->left  = NULL;
  new_node->right = NULL;
  new_node->data =  data;
  return new_node;
}
static struct Tree* insert_node(struct Tree* root, long data){
  if(root == NULL){
    root = create_node(data);
    return root;
  }
  if(data<=root->data){
    root->left = insert_node(root->left, data);
  }
  else{
    root->right = insert_node(root->right, data);
  }
  return root;
}

/* Find MIN:
ALGO:
left most leaf is the smallest element
*/
long find_min(struct Tree* root){
  if (root == NULL){
    printf("The tree is empty: \n");
    return -1;
  }
  while(root->left!=NULL){
    root  = root->left;
  }
  return root->data;
}

/*Find MAX
Algo:
right most leaf is the maximum element
*/

long find_max(struct Tree *root){
  if(root == NULL){
    printf("Tree is empty: \n");
    return -1;
  }
  while(root->right!=NULL){
    root = root->right;
  }
  return root->data;
}

int main(){
  root = NULL;
  root  = insert_node(root, 10);
  root = insert_node(root, 8);
  root = insert_node(root, 35);
  root = insert_node(root, 12);
  root = insert_node(root, 6);
  printf("Minimum Value: %ld \n", find_min(root));
  printf("Maximum Value: %ld \n", find_max(root));
  return 0;
}
