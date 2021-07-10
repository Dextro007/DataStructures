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
 /*
 14
 16
 32
 33
 37
 38
 41
 43
 44
 45
 46
 47
 48
 49
 50
 51
 52
 58
 59
 67
 68
 69
 70
 71
 72
 73
 74
 75
 76
 */
