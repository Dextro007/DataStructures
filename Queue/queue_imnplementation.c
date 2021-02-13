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

enum Bool{
  True,
  False
};
//--------------------------Functions------------------------
enum queueStates isfull(struct Queue* q);
enum queueStates isempty(struct Queue* q);
Bool enqueue(struct Queue* q, long data);
Bool dequeue(struct Queue* q);
struct Queue* createQueue(unsigned long queue_length);
void printQueue(struct Queue *q);
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

enum queueStates isempty(struct Queue* q){
  if(q->head == -1){
    return EMPTY;
  }else{
    return NOT_EMPTY;
  }
}

Bool enqueue(struct Queue *q, long data){
  if(isempty(q) == EMPTY){
    q->array[++q->head] == data;
    q->tail++;

  }else if(isfull(q) == FULL){
    printf("Overflow : The queue is ready full\n");

  }else{

  }
}

int main(){

}
