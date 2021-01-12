#include<stdio.h>
#include<stdlib.h>

unsigned char test_func(){
  int a = 0;
  int *ptr = NULL;
  while(ptr){
    if(a>5)
      break;
    a++;
    // printf("%d\n", a);
  }
  return a;
}

int main(){
   printf("Value of a : %d\n",test_func());
  return 0;
}
