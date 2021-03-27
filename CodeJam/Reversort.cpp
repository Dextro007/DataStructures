#include<iostream>
#include<climits>
using namespace std;

void reverseArray(int arr[], int start, int end){
  int temp;
  while(start<end){
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

int minimum(int arr[],unsigned int start, unsigned int len){
  int mini = INT_MAX;
  int ret_val = 0;
  for(unsigned int i = start; i<len; i++){
    if(arr[i] < mini){
      mini = arr[i];
      ret_val = i;
    }
  }
  return ret_val;
}

int main(){
  int T, N,j;
  int *arr;
  int summ;
  // cout<<"\nEnter T : ";
  cin>>T;
  int *res = new int[T];
  for(int tc = 0; tc< T; tc++){
    // cout<<"\nEnter N : ";
    summ =0;
    cin>>N;
    arr = new int[N];
    for(int element =0; element<N; element++){
      // cout<<"\nEnter element : ";
      cin>>arr[element];
    }
    for(int i = 0; i<= N-2; i++){
      j = minimum(arr,i,N);
      // cout<<"\n j : "<<j;
      summ += j-i+1;
      // cout<<"\n sum : "<<summ;
      reverseArray(arr,i,j);
    }
    res[tc] = summ;
  }
  for(int i=0; i<T; i++){
    cout << "Case #"<<i+1<<": "<<res[i]<<"\n";
  }
  delete arr;
  delete res;
  return 0;
}
