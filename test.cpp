#include<iostream>
#include<utility>
#include<map>
#include<unordered_set>


using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};


int main(){
  map<int,pair<int, int> > m;
  pair<int, int > test;
  unordered_set<int> uset;
  map<int, int > mptest;

  mptest[10] = 5;
  mptest[20] = 10;

  m[0] = make_pair(2,3);
  m[2] = make_pair(1,4);
  test.first = 2; test.second = 3;

  cout<<m[0].first << endl;
  cout << m[2].second<< endl;
  cout << mptest.find(10)->first << endl;

  if (m.find(1) != m.end()) {
    cout << "match found" << endl;
  }
  return 0;
}
