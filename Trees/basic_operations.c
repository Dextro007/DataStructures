/*
Trees can be implemented using:
    1. dynamically created nodes
    2. arrays:
      for arrays node at index i:
        left child  = 2i + 1
        right child  = 2i + 2
        NOTE: giving that we traverse level wise.
*/


#include<stdio.h>
#include<stdlib.h>
#include "basic_operations.h"
// declaring all the static functions needed for a BST.
static void Init();
static unsigned char isEmpty();
static void insert_node();
/*------------------------------------------------------------------*/
static void Init(){
  root = NULL;
}

int main(){
  Init();

  return 0;
}
