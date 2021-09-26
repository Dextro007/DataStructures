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
#include<climits>
using namespace std;
/*
Note that in heap we can insert at leftmost node
and delete only at root.
*/
class minHeap{
  int capacity;
  int *heapArr;
  int size;
public:
  // constructor  for initialization
  minHeap(int capacity);
  void minHeapify(int element);
  // kto return the parent node of i
  int parent(int i){
    return (i-1)/2;
  }
  // for returning the left child of the node i
  int left(int i){ return (2*i)+1; }
  // for returning the right child of the node i
  int right(int i){return (2*i)+2;}
  // to extract and remove the root(minimum element of the heap)
  int extractMin();
  // since deletion is allowed only at root decreaseKey
  // replaces the key to be deleted with INT_MIN and then heapifies that
  void decreaseKey(int i, int newVal);
  void deleteKey(int i);
  void insertKey(int i);
  int getMin(){
    return heapArr[0];
  }
};

// to swap the values at 2 array indexes
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
// constructor created
minHeap::minHeap(int cap){
  size = 0;
  capacity = cap;
  heapArr = new int[capacity];
}
// function removes the root of the heap and return it
// while removing at the root we replace it with the last element of the heap
// and then heapify the heap from 0th element
int minHeap::extractMin(){
  // Incas the size is 0
  if(size == 0){
    return INT_MAX;
  }
  // Incase the size is 1
  if(size == 1){
    size--;
    return heapArr[0];
  }
  int rootData = heapArr[0];
  // replace the root data with last element
  heapArr[0] = heapArr[size-1];
  //decrease the size
  size--;
  // start heapifying from root element
  minHeapify(0);
  return rootData;
}
// convert non-heap to heap
void minHeap::minHeapify(int i){
  int lval = left(i);
  int rval = right(i);
  int smallest = i;
  if(i<size && heapArr[lval]<heapArr[i]){
    smallest = lval;
  }
  if(i<size && heapArr[rval]<heapArr[i]){
    smallest = rval;
  }
  if(smallest != i){
    swap(&heapArr[i], &heapArr[smallest]);
    minHeapify(smallest);
  }
}
// replaces the value with new value(usually INT_MIN) and then
// keeps swapping until it reaches the root
void minHeap::decreaseKey(int i, int newVal){
  heapArr[i] = newVal;
  while(i>0 && heapArr[parent(i)] < heapArr[i]){
    swap(&heapArr[parent(i)], &heapArr[i]);
    i = parent(i);
  }
}

void minHeap::deleteKey(int i){
  decreaseKey(i, INT_MIN);
  extractMin();
}
int main()
{
  int n;
  cin>>n;
  return 0;
}
