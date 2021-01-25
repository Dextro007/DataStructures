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
//-----------------------------FUNCTIONS-DECLARATION----------------------------
void push(struct Stack *stack, long data);
long pop(struct Stack *stack);
unsigned char isEmpty(struct Stack *stack);
unsigned char isFull(struct Stack *stack);
static struct Stack* create_stack(unsigned long capacity);
//----------------------------*****************---------------------------------

// function to create and initialize the structure parameters
static struct Stack* create_stack(unsigned long capacity){
  struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack));
  new_stack->capacity = capacity;
  //since 1st element in the stack will be at index 0;
  new_stack->top = -1;
}

// function to check if the 
int main(){

  return 0;
}
