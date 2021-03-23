#include<iostream>
#include<climits>
#include<array>
using namespace std;

long ret_max(long arr[], unsigned long size){
  long max = INT_MIN;
  for(unsigned long i=0; i<size; i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}

int main(){
  long arr[10] = {0};
  return 0;
}
