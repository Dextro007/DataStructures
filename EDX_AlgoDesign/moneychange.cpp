#include<iostream>
using namespace std;

int money_change(int m){
  int tens,fives,ones;
  tens=m/10;
  fives = (m%10)/5;
  ones = (m%10)%5;
  return tens+ones+fives;
}

int main(){
  int m;
  cin>>m;
  cout<<money_change(m);
  return 0;
}
