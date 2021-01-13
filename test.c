#include<stdio.h>
#include<stdlib.h>

static unsigned int counter = 0;

void test_func(){
  counter++;
  if(counter > 15){
    counter = 0;
  }
}

int main(){
  test_func();
  return 0;
}
