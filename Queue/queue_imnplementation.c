/*
Problem :         Implementing queue
Approach :        using arrays
*/

#include<stdio.h>
#include<stdlib.h>
struct Queue{
  unsigned long length;
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
struct Queue* createQueue(unsigned long queue_length);
//-----------------------------------------------------------

struct Queue* createQueue(unsigned long queue_length){
  struct Queue *new_queue = (struct Queue*)malloc(sizeof(struct Queue));
}

enum queueStates isfull(struct Queue* q){

}

int main(){

}
