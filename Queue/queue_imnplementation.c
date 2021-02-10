/*
Problem :         Implementing queue (dumb queue)
Approach :        using arrays
*/

#include<stdio.h>
#include<stdlib.h>
struct Queue{
  // unsigned long length;
  //deletion at tail
  long head;
  // insertion at head
  long tail;
  long *array;
  unsigned long capacity;
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
long enqueue(struct Queue* q, long data);
long dequeue(struct Queue* q);
struct Queue* createQueue(unsigned long queue_length);
//-----------------------------------------------------------

struct Queue* createQueue(unsigned long queue_capacity){
  struct Queue *new_queue = (struct Queue*)malloc(sizeof(struct Queue));
  new_queue->capacity = queue_capacity;
  new_queue->tail = new_queue->head = -1;
  new_queue->array = (long *)malloc(queue_capacity * sizeof(long));
  return new_queue;
}

enum queueStates isfull(struct Queue* q){
  if(q->head == q->capacity){
    return FULL;
  }else{
    return NOT_FULL;
  }
}

int main(){

}
