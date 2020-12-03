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

static void Init();
// stat

void dummy(){
  printf("dummy function called");
}

// int main(){
//   printf("Hello");
//   return 0;
// }
