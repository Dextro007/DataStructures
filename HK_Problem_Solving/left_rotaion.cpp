/*
Prblm : Predict a given array "arr" of length "size" after left rotaion "r"
Solution : This problem can be solved in O(n) by instead of rotating the array
          we directly predict the position of " i "th member after "r" rotations
Technique : significant_rotations  = r % size
            new_index = ((i - significant_rotations) + size) % size
            newArray[new_index] = arr[i]
*/
#include<iostream>

using namespace std;

long* left_rotation(long arr[], long rotations, long new_array[], long size){
  long new_idx;
  for(long i=0; i<size; i++){
    new_idx = (((i - (rotations%size)) + size) % size);
    new_array[new_idx] = arr[i];
  }
  return new_array;
}

int main(){
  long n,rotations;
  cin>> n >> rotations;
  long arr[n], rotated_array[n];
  for(long i=0; i<n; i++){
    cin>>arr[i];
  }
  left_rotation(arr, rotations, rotated_array, n);
  for(long i = 0; i<n; i++){
    cout<<rotated_array[i]<< " ";
  }
  return 0;
}
