#include<iostream>

using namespace std;
int main(){
  unsigned short int a;
  unsigned short int b;
  unsigned short int c;
  a = 65535;
  b = 1;
  c = 1;
  a &= (~b);
  a &= (~c);
  cout<<"a: "<<a<<"\n";
  cout<<"b: "<<b<<"\n";
  cout<<"c: "<<c<<"\n";
  cout<<"~ b: "<<(unsigned short int)~b<<"\n";
  cout<<"~ c: "<<(unsigned short int)~c<<"\n";
  cout<<"a&b "<<(a&b)<<"\n";
  return 0;
}
