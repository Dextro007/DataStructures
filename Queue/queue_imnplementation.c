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
enum queueStates isfull(struct Queue* q);
enum queueStates isEmpty(struct Queue* q);
long push_back(struct Queue* q, long data);
long pop_front(struct Queue* q);


int main(){

}
