#include<iostream>
#include<utility>
#include<map>

using namespace std;
int main(){
  map<int,pair<int, int>> m;
  m[0] = make_pair(2,3);
  m[1] = make_pair(1,4);
  cout<<m[0].first;  
  return 0;
}
