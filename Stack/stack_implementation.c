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
}

// function to check if the stack is is isFull

int main(){

  return 0;
}
