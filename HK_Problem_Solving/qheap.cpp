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
Arr[(i-1)/2]    Returns the parent node
Arr[(2*i)+1]    Returns the left child node
Arr[(2*i)+2]    Returns the right child node
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
  void printHeap(){
    for(int i = 0; i<size; i++){
      cout<<heapArr[i]<<" ";
    }
    cout<<"\n";
  }
  int getMin(){
    return heapArr[0];
  }
  int getIndex(int element);
};

// to swap the values at 2 array indexes
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
// constructor create
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
  if(size <= 0){
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
  // cout<<"\n extmin: "<< heapArr[0]<< "\n";
  //decrease the size
  size--;
  // start heapifying from root element
  // printHeap();
  minHeapify(0);
  return rootData;
}
// convert non-heap to heap
void minHeap::minHeapify(int i){
  int lval = left(i);
  int rval = right(i);
  int smallest = i;
  if(lval < size && heapArr[lval]<heapArr[i]){
    smallest = lval;
  }
  if(rval < size && heapArr[rval]<heapArr[smallest]){
    smallest = rval;
  }
  if(smallest != i){
    swap(&heapArr[i], &heapArr[smallest]);
    // printHeap();
    minHeapify(smallest);
  }
}
// replaces the value with new value(usually INT_MIN) and then
// keeps swapping until it reaches the root
void minHeap::decreaseKey(int i, int newVal){
  heapArr[i] = newVal;
  while(i!=0 && heapArr[parent(i)] > heapArr[i]){
    swap(&heapArr[parent(i)], &heapArr[i]);
    i = parent(i);
  }
}

void minHeap::deleteKey(int i){
  decreaseKey(i, INT_MIN);
  extractMin();
}
void minHeap::insertKey(int i){
  if(size == capacity){
    cout<<"Overflow, Can't Insert"<<"\n";
    return;
  }
  heapArr[size++] = i;
  int node = size-1;
  while(node!=0 && heapArr[parent(node)] > heapArr[node]){
    swap(&heapArr[parent(node)], &heapArr[node]);
    node = parent(node);
  }
}
// to get the index of the heap elements
int minHeap::getIndex(int element){
  for(int i=0; i<size; i++){
    if(heapArr[i] == element){
      return i;
    }
  }
  return -1;
}

int main()
{
  int  q,val, n,index;
  cin>>n;
  minHeap h(n);
  for( int i = 0; i<n; i++){
    cin>>q;
    switch(q){
      case 1:
        cin>>val;
        h.insertKey(val);
      break;
      case 2:
        cin>>val;
        index = h.getIndex(val);
        if(index>=0)
          h.deleteKey(index);
      break;
      case 3:
      cout<<h.getMin()<<"\n";
      break;
      default:
      cout<<"Invalid Input";
    }
  }
  return 0;
}
