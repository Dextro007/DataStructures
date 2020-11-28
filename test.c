#include<stdio.h>
#include<stdlib.h>

unsigned char test_func(){
  int a=5, b=5;
  return a==b;
}

int main(){
  printf("The result is : %d\n", test_func());
  return 0;
}
