/*
Problem :         Implementing queue (dumb queue), not flexible ech deletion
                  decrease the size of queue;
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
  TRUE,
  FALSE
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
  Bool ret_val;
  if(isempty(q) == EMPTY){
    q->array[++q->head] = data;
    q->tail++;
    printf("%ld enqueued to the queue\n", q->array[q->head]);
    ret_val = TRUE;
  }
  else if(isfull(q) == FULL){
    printf("Overflow : The queue is ready full\n");
    ret_val = FALSE;
  }
  else{
    q->array[++q->head] = data;
    printf("%ld enqueued to the queue\n", q->array[q->head]);
    ret_val = TRUE;
  }
  return ret_val;
}

Bool dequeue(struct Queue* q){
  Bool ret_val;
  if(isempty(q) == EMPTY){
    printf("Underflow : Queue is empty \n");
    ret_val = FALSE;
  }
  else{
    printf("%ld dequeued from the queue: ", q->tail++);
    ret_val = TRUE;
  }
  return ret_val;
}

int main(){
  unsigned long capacity = 10;          // capacity of queue
  struct Queue *queue = createQueue(capacity);
  enqueue(queue, 10);
  enqueue(queue, 9);
  enqueue(queue, 8);
  enqueue(queue, 7);
  enqueue(queue, 6);
  enqueue(queue, 5);
  enqueue(queue, 4);
  dequeue(queue);

  return 0;
}
