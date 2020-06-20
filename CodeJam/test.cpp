#include<iostream>
#include<set>
using namespace std;

int main(){
  set<int> st;
  int n=3;
  int arr[n][n];
  for(int i = 0; i<n; i++){
    for(int j=0; j<n;j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 0; i<n; i++){
    for(int j=0; j<n;j++){
      st.insert(arr[i][j]);
    }
  }
  set<int>::iterator it;
  for(it = st.begin(); it!= st.end(); it++)
    cout<<*it<<" ";
}
