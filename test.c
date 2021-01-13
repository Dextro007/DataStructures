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
  for(int i = 0; i<48; i++){
    test_func();
    printf("%u\t", counter);
  }
  printf("\n");
  return 0;
}
