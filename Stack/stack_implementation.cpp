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
    array = new long[capacity];
  }
  bool push(long data);
  bool pop();
  void view_top();
  bool isEmpty();
  bool isFull();
};


bool Stack::isFull(){
  // top should start with -1, also the max capacity = 2147483648(max signed long)
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
bool Stack::pop(){
  bool ret_value = false;
  if(isEmpty()){
    cout<<"Error: The stack is empty, nothing to delete. \n";
  }else{
    cout<< array[top--]<<" Deleted from the stack\n";
    ret_value = true;
  }
  return ret_value;
}

void functionality_test(unsigned long capacity){
  Stack s(capacity);
  s.push(6);
  s.push(4);
  s.push(2);
  s.push(5);
  s.push(1);
  s.push(7);
  s.push(8);
  s.push(10);
  s.push(9);
  s.push(3);
  s.push(11);
  s.push(12);
  s.view_top();
  s.pop();
  s.view_top();
}
int main(){
  unsigned long capacity = 10;
  functionality_test(capacity);
  return 0;
}
