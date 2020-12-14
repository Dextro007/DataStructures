#include<stdio.h>
#include<stdlib.h>

struct Tree{
  long data;
  struct Tree *left;
  struct Tree *right;
};

struct Tree *root = NULL;

static struct Tree* create_node(long data);
static struct Tree* insert_node(struct Tree*, long data);


int main(){
  return 0;
}
