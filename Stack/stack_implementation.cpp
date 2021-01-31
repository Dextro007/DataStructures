#include<iostream>

using namespace std;

class stack{
private:
  long top;
  unsigned long capacity;
  long *array;
public:
  bool push(long data);
  bool pop();
  long view_top();
  bool isEmpty();
};
bool Stack::push()
