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
  long view_top();
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
