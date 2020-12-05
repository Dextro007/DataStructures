/*
Trees can be implemented using:
    1. dynamically created nodes
    2. arrays:
      for arrays node at index i:
        left child  = 2i + 1
        right child  = 2i + 2
        NOTE: giving that we traverse level wise.
*/
#ifndef BASIC_OPERATION
#define BASIC_OPERATION

struct Tree{
  int data;
  struct Tree *left;
  struct Tree *right;
};

// extern struct Tree *root;
extern unsigned long calc_height();
extern unsigned long total_nodes();
#endif
