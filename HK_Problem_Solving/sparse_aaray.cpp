#include<iostream>
#include<string>
using namespace std;

void sparse_array(string strings[], string queries[], int results[], int n, int q){
  for(int i = 0; i<q; i++){
    for(int j = 0; j<n; j++){
      if(queries[i] == strings[j])
        results[i]++;
    }
    //cout<<results[i]<<"\n";
  }
  return;
}

int main(){
  int n,q;
  cin>>n;
  string strings[n];
  for(int i = 0; i<n; i++){
    cin>>strings[i];
  }
  cin>>q;
  int results[q] = {0};
  string queries[q];
  for(int i=0; i<q; i++){
    cin>>queries[i];
  }
  sparse_array(strings, queries, results, n, q);
  for(int i =0; i<q; i++){
    cout<<results[i]<<"\n";
  }
  return 0;
}
