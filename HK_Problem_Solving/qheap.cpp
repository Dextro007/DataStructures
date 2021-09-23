/*
Prblm  : perfrom basic opertaions on the heap
Soln  : Construct a min heap or maxheap
      Heaps are conmstructed using arrays as it is a complete binary tree
How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

The root element will be at Arr[0].
Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node
*/
#include<iostream>

using namespace std;

class minHeap{
  int capacity;
  int *arr;
  int size;
public:
  // constructor  for initialization
  minHeap(int capacity);
  void minheapify(int);

  int parent(int i){
    return (i-1)/2;
  }
  int left(int i){ return (2*i)+1; }
  int extractMin();
};

int main()
{
  int n;
  cin>>n;
  return 0;
}
