#include<bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin>>tc;
  for(int i =1; i<=tc; i++){
    int x,y;
    cin>>x>>y;
    string str;
    cin>>str;
    int cost = 0;
    int len = str.length();
    int pre = 'I';
    for(int j=0; j<len; j++){
      if(str[j]=='C'){
        if(pre == 'J'){
          cost += y;
        }
        pre = 'C';
      }
      else if(str[j] == 'J'){
        if(pre == 'C'){
          cost += x;
        }
        pre = 'J';
      }
      else{

      }
    }
    cout<<"Case #"<<i<<": "<<cost<<endl;
  }
}
