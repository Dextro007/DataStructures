#include<stdio.h>
#include<stdlib.h>

// static unsigned int counter = 0;

void test_func(int *arr, int size){
  for(int i = 0; i<size; i++){
    arr[i] = i+1;
  }
  return;
}

int main(){
  int *ptr = NULL;

  test_func(ptr, 5);
  for(int i=0; i<5; i++){
    printf("%d", ptr[i]);
  }
  return 0;
}
