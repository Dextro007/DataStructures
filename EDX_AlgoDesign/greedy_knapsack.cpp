#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


float greedy_knapsack(long W, vector<long> weight, vector<long> value, int n ){
  vector<long> amount(n,0);
  vector<float> rate;
  long amountToTake;
  float totalValue = 0;
  for(int i=0; i<n; i++){
    if(value[i]>0){
      rate.push_back((float)((float)value[i]/(float)weight[i]));
      //cout<<"Rate :"<<rate[i]<<"\n";
    }
  }
  make_heap(rate.begin(), rate.end());
  sort_heap(rate.begin(), rate.end());
  //cout<<rate[0]<<"\n";
  for(int i = n-1; i>=0; i--){
    if(W==0){
      return totalValue;
    }
    if(W<weight[i])
      amountToTake = W;
    else
      amountToTake = weight[i];
    //cout<<"AMount : "<<amountToTake<<"\n";
    totalValue = totalValue + amountToTake * rate[i];
    W = W - amountToTake;
    amount[i] = amount[i] + amountToTake;
    weight[i] = weight[i] - amountToTake;
  }
  return totalValue;
}

int main(){
  vector<long> weight;
  vector<long> value;
  long W, vi, wi;
  int n;
  cin>>n>>W;
  for(int i=0; i<n; i++){
    cin>>vi>>wi;
    value.push_back(vi);
    weight.push_back(wi);
  }
  cout<<greedy_knapsack(W,weight, value, n);
  return 0;
}
