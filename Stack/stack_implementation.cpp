#include<iostream>

using namespace std;

class Stack{
private:
  long top;
  unsigned long capacity;
  long *array;
public:
  // constructor to initialize the parameters
  Stack(unsigned long stack_capacity){
    top = -1;
    capacity = stack_capacity;
    array = new long[stack_capacity];
  }
  bool push(long data);
  bool pop();
  void view_top();
  bool isEmpty();
  bool isFull();
};


bool Stack::isFull(){
  if(top == capacity){
    return true;
  }
  else{
    return false;
  }
}

bool Stack::isEmpty(){
  if(top == -1){
    return true;
  }else{
    return false;
  }
}

void Stack::view_top(){
  if(isEmpty()){
    cout<<"The stack is empty, nothing to print\n";
    return;
  }else{
    cout<< "Top of Stack: "<<array[top]<<"\n";
  }
  return;
}
bool Stack::push(long data){
  if(isFull()){
    cout<< "Overflow : Can't insert the stack is full"<< "\n";
    return false;
  }
  else{
    array[++top] = data;
    cout<<data<<" pushed to the stack"<< "\n";
    return true;
  }
}
