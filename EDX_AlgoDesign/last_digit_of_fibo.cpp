#include<iostream>

using namespace std;

int calc_last_digit(long long n){
  if(n<2){
    return n;
  }
  int a=0,b=1;
  int c;
  for(long long i=0; i<n; i++){
    c = (a+b)%10;
    a = b;
    b = c;
  }
  return (c+1)%10;
}

int main(){
  long long n;
  cin>>n;
  cout<<calc_last_digit(n);
  return 0;
}
