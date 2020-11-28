/*
AIM : add 1 to a linked list storing numbers
Approach : 1. reverse the linked list for convinience as we
            start adding from right most
            2. handle the carry
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *link;
};
struct Node *head;
unsigned char isEmpty(){
  return head == NULL;
}
void reverse_list(){
  if(isEmpty()){
    printf("The list is empty. \n");
    return;
  }
  struct Node *current_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *previous_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *next_node = (struct Node*)malloc(sizeof(struct Node));
  previous_node = NULL;
  current_node = head;
  while(current_node->link != NULL){
    next_node = current_node->link;
    current_node->link = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }
  next_node = current_node->link; //basically making next =NULL
  current_node->link = previous_node;
  head = current_node;\
  return;
}
void addOne(){
  return;
}
// test function
void push(int data){
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->link = NULL;
  // handling empty list condition
  if(head == NULL){
   head = new_node;
  }
  else{
    struct Node *previous_node = (struct Node*)malloc(sizeof(struct Node));
    previous_node = head;
    while(previous_node->link != NULL){
      previous_node = previous_node->link;
    }
    previous_node->link = new_node;
  }
  return;
}

// function to print the list in forward
void print_list(){
  struct Node *traverse_node = (struct Node*)malloc(sizeof(struct Node));
  traverse_node =  head;
  int i = 0;
  while(traverse_node->link != NULL){
    printf("Element at %d position is : %d \n", i, traverse_node->data);
    traverse_node = traverse_node->link;
    i++;
  }
  printf("Element at %d position is : %d \n", i, traverse_node->data);
  return;
}

int main(){
  head = NULL;
  push(10);
  push(7);
  push(6);
  print_list();
  return 0;
}
