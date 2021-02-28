/*
AIM :         Circular queue implementation
Approach:     We implement circular queues using array. Here the head and tail
            literaly doesn't mean the same, and are basically two calculated array
            index. So don't get confused.
*/


#include<stdio.h>
#include<stdlib.h>

struct Cqueue{
  unsigned long size;
  unsigned long capacity;
  unsigned long head;
  unsigned long tail;
  long *array;
};

enum queueStates{
  EMPTY,
  NOT_EMPTY,
  FULL,
  NOT_FULL,
};
//---------------------Functions------------------------
enum queueStates isfull(struct Cqueue *Cq);
enum queueStates isempty(struct Cqueue *Cq);
void enqueue(struct Cqueue *Cq, long data);
void dequeue(struct Cqueue *Cq);
struct Cqueue* createQueue(unsigned long queue_capacity);
void printQueue(struct Cqueue *Cq);
//------------------------------------------------------

struct Cqueue* createQueue(unsigned long queue_capacity){
  struct Cqueue *circular_queue = (struct Cqueue*)malloc(sizeof(struct Cqueue));
  circular_queue->capacity = queue_capacity;
  circular_queue->size = 0;
  circular_queue->head = circular_queue->tail = -1;
  circular_queue->array = (long *)malloc(queue_capacity * sizeof(long));
  return circular_queue;
}

enum queueStates isfull(struct Cqueue *cq){
  if(cq->size == cq->capacity){
    return FULL;
  }
  else{
    return NOT_FULL;
  }
}

enum queueStates isempty(struct Cqueue *cq){
  if(cq->size == 0){
    return EMPTY;
  }
  else{
    return NOT_EMPTY;
  }
}
void enqueue(struct Cqueue *Cq, long data){
  if(isfull(Cq) == FULL){
    printf("Overflow: The queue is already full. \n");
    return;
  }
  else{
    Cq->head = (Cq->head + 1) % (Cq->capacity);
    Cq->array[Cq->head] = data;
    printf("%ld was enqueued in the queue\n", Cq->array[Cq->head]);
    Cq->size += 1;
    return;
  }
}

void dequeue(struct Cqueue *Cq){
  if(isempty(Cq) == EMPTY){
    printf("The stack is empty\n");
    return;
  }
  else{
    printf("%ld dequeued from the queue.\n", Cq->array[Cq->tail]);
    Cq->tail = (Cq->tail + 1)%Cq->capacity;
    Cq->size -= 1;
  }
  return;
}

int main(){

  return 0;
}
