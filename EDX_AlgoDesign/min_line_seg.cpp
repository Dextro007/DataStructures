/*
Prblm :  You are responsible for collecting signatures from all tenants of a certain build-ing.
        For each tenant, you know a period of time when he or she is at home.You would like to collect all signatures by visiting
        the building as few times aspossible.
Mathematical model: given a setof segments on a line and your goal is to mark as few points on a line as possibleso that each segment
        contains at least one marked point

DS/algo used : array/vector
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  vector<long> vec;
  int n= 200;
  for(int i = 0;i<n; i++){
    cin>>vec[i];
  }
  return 0;
}
