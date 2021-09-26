/*
Prblm  : perfrom basic opertaions on the heap
There are 3 types of query:

"1 v" - Add an element v to the heap.
"2 v" - Delete the element v from the heap.
"3" - Print the minimum of all the elements in the heap.

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
/*
Note that in heap we can insert at leftmost node
and delete only at root.
*/
class minHeap{
  int capacity;
  int *HeapArr;
  int Hsize;
public:
  // constructor  for initialization
  minHeap(int capacity);
  void minheapify(int);
  // kto return the parent node of i
  int parent(int i){
    return (i-1)/2;
  }
  // for returning the left child of the node i
  int left(int i){ return (2*i)+1; }
  // for returning the right child of the node i
  int right(int i){return (2*i)+2;}
  // to extract the root(minimum element of the heap)
  int extractMin();
  // since deletion is allowed only at root decreaseKey
  // replaces the key to eb delete with INT_MIN and then heapifies that
  void decreaseKey(int i);

  void insertKey(int i);
  int getMin(){
    return HeapArr[0]
  }

};
// constructor created
minHeap::minHeap(int cap){
  Hsize = 0;
  capacity = cap;
  HeapArr = new int[capacity];
}


int main()
{
  int n;
  cin>>n;
  return 0;
}
