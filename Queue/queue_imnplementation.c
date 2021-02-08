/*
Problem :         Implementing queue
Approach :        using arrays
*/

#include<stdio.h>

struct Queue{
  unsigned long capacity;
  long head;
  long tail;
  long *array;
};
enum queueStates{
  EMPTY,
  FULL,
  NOT_EMPTY,
  NOT_FULL
};

//--------------------------Functions------------------------
void isfull(struct Queue* q);

int main(){

}
