/*
Problem Statment - 1. write a function to insert data at beginning of a linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* link;
};
struct Node* head;

// to check whether the list is empty
unsigned char isEmpty(){
  if(head == NULL)
    return 1;
  else
    return 0;
}
// to insert data at the beginning of the list
void insert_at_beginning(int number){
  struct Node* temp = (Node*)malloc(sizeof(struct Node));
  temp->data = number;
  temp->link = NULL;
  if(head != NULL){
    temp->link = head;
    head = temp;
  }
  else
    head = temp;
  return;
}

// to insert data at the nth position
void insert_at_n(int n, int data){
  struct Node* temp = (Node*)malloc(sizeof(struct Node));
  if(n==0 || n==1){
    insert_at_beginning(data);
  }
}
//print the elements of list
void print_list(){
  struct Node* temp = (Node*)malloc(sizeof(struct Node));
  temp->link = head;
  while(temp->link != NULL){
    printf("%d", temp->data);
    temp = temp->link;
  }
  printf("\n");
  return;
}

int main(){
    int n,i,number;
    head = NULL;
    printf("Enter number of insertion: ");
    scanf("%d", &n);
    for( i=0; i<n; i++){
      printf("enter the value to be inserted :");
      scanf("%d", &number);
      insert_at_beginning(number);
     }
     return 0;
}
