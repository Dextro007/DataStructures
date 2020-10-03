/*
Soln : No need to swap values, no need to loop backwards, no need to loop more than once.
        Just loop through each person in the queue and check two things:
        1. Has this person moved more than two positions forward?
        2. How many times has this person been bribed?
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}
void calculate_chaos(vector<int> queue){
  int count = 0;
  for(int i = queue.size()-1; i>=0; i--){
    if(queue[i] - (i+1) > 2){
      cout<<"Too chaotic"<<"\n";
      return;
    }
    for(int j = max(0, queue[i]-2); j<i; j++){
      if(queue[j]>queue[i]){
        count++;
      }
    }
  }
  cout<<count<<"\n";

}
rr
int main(){
  int test_cases;
  int n, element;
  vector<int> queue;
  cin>>test_cases;
  for(int i = 0; i<test_cases; i++){
    cin>>n;
    queue.clear();
    //queue.resize(n);
    for(int i = 0; i<n; i++){
      cin>>element;
      queue.push_back(element);
    }
    calculate_chaos(queue);
  }
  return 0;
}
