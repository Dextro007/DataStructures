#include<iostream>

using namespace std;

void right_rotation(long arr[], long rotations, long new_array[], long size){

}

int main(){
  int t;
  cin>>t;
  long rotations,n;
  for(int i = 0; i<t; i++){
    cin>>n;
    cin>>rotations;
    long *arr = new int[n];
    long *new_array = new int[n];
    for(int j = 0; j<n; j++){
      cin>>arr[j];
    }
    right_rotation(arr, rotations, new_array, n);
    for(int j=0; j<n; j++){
      cout<<new_array[j];
    }
    delete arr;
    delete new_array;
  }

  return 0;
}
