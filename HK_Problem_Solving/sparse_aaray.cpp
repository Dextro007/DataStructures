#include<iostream>
#include<string>

using namespace std;

int main(){
  string str1 = "ab";
  char a = 'A';
  if(str1 == string(1, a)){
    cout<<"Same \n";
  }
  else{
    cout<<"Different \n";
  }
  return 0;
}
