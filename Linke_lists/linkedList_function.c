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
