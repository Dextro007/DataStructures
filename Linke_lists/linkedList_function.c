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
  temp->link = head;
  head = temp;
  return;
}

// to insert data at the nth position
void insert_at_n(int n, int data){
  struct Node* new_node = (Node*)malloc(sizeof(struct Node));
  if(n==0){
    insert_at_beginning(data);
  }
  else if(n == 1){
    new_node->data = data;
    new_node->link = head;
    head = new_node;
  }
  //traversing through the linked list
  struct Node* previous_node = head;
  for(int i=0; i<n-1; i++){
    previous_node = previous_node->link;
  }
  new_node->data = data;
  new_node->link = previous_node->link;
  previous_node->link = new_node;
  return;
}

// function to delete node at nth position
void delete_nth(int n){
  struct Node* previous_node = (Node*)malloc(sizeof(struct Node));
  int i;
  previous_node = head;
  for(i=0; i<n-2; i++){
    previous_node  = previous_node->link;
  }
  struct Node* current_node = (Node*)malloc(sizeof(struct Node));
  current_node = previous_node->link;
  previous_node->link = current_node->link;
  free(current_node);
  return;
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
