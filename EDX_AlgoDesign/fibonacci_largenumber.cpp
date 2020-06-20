/* Fibonaccci number for a huge n can be calculated using the formula
Fn = {[(√5 + 1)/2] ^ n} / √5
*/

#include<iostream>
#include<math.h>
using namespace std;
/*  // TC = O(n), SC = O(1)
long long fibonacci_modulo(long long n, long long m){
  if(n==0){
    return n;
  }
  long long a,b,fib;
  a = 0;
  b = 1;
  for(long long i = 0; i< n-1; i++){
    fib = a+b;
    a = b;
    b = fib;
  }
  cout<<fib<<"\n";
  return (fib%m) ;
}
*/

// using formula
long long fibonacci_formula(long long n){
  long long ret;
  double phi = (1 + sqrt(5))/2;
  //cout<<"Phi: "<<phi<<"\n";
  cout<<"Raw Ret"<<pow(phi, n)/sqrt(5)<<"\n";
  ret = pow(phi, n)/sqrt(5);
  cout<<ret<<"\n";
  return ret;
}

using namespace std;
int main(){
  long long n,m;
  cin>>n>>m;
  cout<<(long long)(fibonacci_formula(n) % m);
  return 0;
}
