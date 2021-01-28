/*
AIM         : Implementation of stacks
Approach    : Using arrays
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
  long top;
  unsigned long capacity;
  long *array;
};
// enum to describe different states of a stack
enum stack_status{
  EMPTY,
  NOT_EMPTY,
  FULL,
  NOT_FULL,
};
//-----------------------------FUNCTIONS-DECLARATION----------------------------
void push(struct Stack *stack, long data);
long pop(struct Stack *stack);
enum stack_status isEmpty(struct Stack *stack);
enum stack_status isFull(struct Stack *stack);
static struct Stack* create_stack(unsigned long capacity);
//----------------------------*****************---------------------------------

// function to create and initialize the structure parameters
static struct Stack* create_stack(unsigned long capacity){
  struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack));
  new_stack->capacity = capacity;
  //since 1st element in the stack will be at index 0;
  new_stack->top = -1;
  new_stack->array = (long *)malloc(new_stack->capacity * sizeof(long));
  return new_stack;
}

// function to check if the stack is is isFull
enum stack_status isEmpty(struct Stack *stack){
  if(stack->top == -1){
    return EMPTY;
  }
  else{
    return NOT_EMPTY;
  }
}

enum stack_status isFull(struct Stack *stack){
  if(stack->top == stack->capacity - 1){
    return FULL;
  }
  else{
    return NOT_FULL;
  }
}
void push(struct Stack *stack, long data){
  if(isFull(stack) == FULL){
    printf("Overflow: The stack is full\n");
  }
  else{
    stack->array[++stack->top] = data;
    printf("Item %ld pushed\n", data);
  }
  return;
}

long pop(struct Stack *stack){
  if(isEmpty(stack) == EMPTY){
    printf("Underflow: the stack is empty.\n");
    return NULL;
  }
  else{
    return stack->array[stack->top--];
  }
}
int main(){
  unsigned long stack_capacity = 7;
  struct Stack *stack = create_stack(stack_capacity);
  push(stack, 2);
  push(stack, 4);
  push(stack, 1);
  push(stack, 5);
  push(stack, 7);
  push(stack, 8);
  push(stack, 11);
  // checking the overflow of stack
  push(stack, 12);
  // to check the stack current length
  printf("Current capacity is stack is: %ld \n", stack->top);
  // to check the top element of the stack
  printf("Top of the stack is : %ld \n", stack->array[stack->top]);
  return 0;
}
