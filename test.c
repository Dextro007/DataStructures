#include<stdio.h>
#include<stdlib.h>

// static unsigned int counter = 0;

void test_func(){
  short signed int a = 12;
  printf("%u", (unsigned short int)(~a+1));
}

int main(){
  test_func();
  return 0;
}
