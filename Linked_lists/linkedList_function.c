/*
Problem Statment - write functions to:
      1.insert at the beginning of a linked list
      2. insert at nth position
      3. push
      4. pop
      5. delete at nth position
      6. print list
      7. reverse a linked list

approach : reverse the linked list:
    1. make 3 nodes, next, current, previous
    2. Initialize previous node to NULL, current_node = head
    3. Traverse and
        move next node to current_node's link
    4. point current_node's link to previous_node
    5. move previous_node to current_node
    6. move current_node to next_node
    7. handle the last node containing NULL out of while
    8. update the head to current_node
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node* link;
};
struct Node* head;

// stores length of the list should be modified after each insertion and deletion
unsigned long listLength = 0;

// to check whether the list is empty
unsigned char isEmpty(){
  if(head == NULL)
    return 1;
  else
    return 0;
}
// to insert data at the beginning of the list
void insert_at_beginning(int number){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = number;
  temp->link = head;
  head = temp;
  listLength++;
  return;
}

// to insert data at the nth position
void insert_at_n(int n, int data){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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
  listLength++;
  return;
}

// function to insert data at end
void push(int data){
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->link = NULL;
  listLength++;
  if(isEmpty()){
    head = new_node;
    return;
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

// function to delete node at nth position
void delete_nth(int n){
  // check if the list is empty.
  if(head == NULL){
    printf("The list is empty nothing to delete \n");
    return;
  }
  else{
    struct Node* previous_node = (struct Node*)malloc(sizeof(struct Node));
    int i;
    previous_node = head;
    for(i=0; i<n-2; i++){
      previous_node  = previous_node->link;
    }
    struct Node* current_node = (struct Node*)malloc(sizeof(struct Node));
    current_node = previous_node->link;
    previous_node->link = current_node->link;
    free(current_node);
    listLength--;
  }
  return;
}

//print the elements of list
void print_list(){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp = head;
  int i = 0;
  while(temp->link != NULL){
    printf("Element at %d position is : %d \n", i, temp->data);
    temp = temp->link;
  }
  printf("Element at %d position is : %d \n", i, temp->data);
  printf("----------END OF LIST-------------\n");
  return;
}

//reverse the linked list
void reverse_list(){
  if(isEmpty()){
    printf("List is Empty.");
    return;
  }
  struct Node *next_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *current_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node *previous_node = (struct Node*)malloc(sizeof(struct Node));
  // struct Node *next = (struct Node*)malloc(sizeof(struct Node));
  previous_node = NULL;
  current_node = head;
  while(current_node->link != NULL){
    next_node = current_node->link;
    current_node->link = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }
  next_node = current_node->link;
  current_node->link = previous_node;
  head = current_node;
  return;
}
// funtion to implement pop functionality(deleting at end)
void pop(){
  struct Node *current_node, *previous_node = (struct Node *)malloc(sizeof(struct Node));
  current_node = head;
  while(current_node->link != NULL){
    previous_node->link = current_node;
    current_node->link = current_node->link;
  }
  previous_node->link = NULL;
  free(current_node);
  return;
}
//-------------

int main(){
    int n,i,number;
    head = NULL;
    push(10);
    push(7);
    push(5);
    push(4);
    push(9);
    push(3);
    insert_at_n(3,11);
    print_list();
    delete_nth(2);
    insert_at_beginning(1);
    // printf("Enter number of insertion: ");
    // scanf("%d", &n);
    // for( i=0; i<n; i++){
    //   printf("\n Enter the value to be inserted :");
    //   scanf("%d", &number);
    //   insert_at_beginning(number);
    //  }
     print_list();
     printf("length of the Linked list is : %lu\n", listLength);
     reverse_list();
     printf("The reversed list is: \n");
     print_list();
     return 0;
}
