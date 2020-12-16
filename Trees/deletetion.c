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

//-----------------------FUNCTIONS-----------------------
static struct Tree* create_node(long data);
static struct Tree* insert_node(struct Tree* root, long data);
static struct Tree* search(struct Tree* root, long data);
static void delete_node(long data);
