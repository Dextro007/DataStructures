#include<iostream>
#include<climits>
#include<array>
using namespace std;

typedef unsigned long UL;

long ret_max(long arr[], UL size){
  long maxx = INT_MIN;
  long summ =0;
  for(UL i=1; i<=size; i++){
      summ += arr[i];
      maxx = max(summ, maxx);
  }
  return maxx;
}

void manipulation(long arr[], UL size, UL a, UL b, long k){
    // for(UL i=(UL)(a-1); i<b;i++){
    //     arr[i] += k;
    //   cout<<i<<"\t"<<arr[i]<<"\n";
    // cout<<"****"<<"\n";
    // }
    arr[a] += k;
    if(b+1 <= size){
        arr[b+1] -= k;
    }
  return;
}

int main(){
  UL arrSize, a, b, operations;
  long k;
  cin>>arrSize>>operations;
//   long arr[arrSize] = {0};
  long *arr = new long[arrSize+1]{0}; // always use dynamic memory allocation
  for(UL i = 0; i<operations; i++){
    cin>>a>>b>>k;
    manipulation(arr, arrSize, a, b, k);
    // cout<<a<<" "<<b<<" "<<k<<" "<<"reached\n";
  }
  cout<<ret_max(arr, arrSize);
  return 0;
}
