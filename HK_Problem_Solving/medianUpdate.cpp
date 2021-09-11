#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

//debug
void printVect(vector<int>vec){
    for (int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void printMedian(vector<int> vect){
    int midVal;
    float mid;
    if(vect.size() == 0){
        cout<<"Wrong!";
    }else{
        if(vect.size()%2 != 0){
        cout<<vect[floor(vect.size()/2)]<<"\n";
     }
        else{
            midVal = vect.size()/2;
            // cout<<"mid "<<midVal<<"\n";
            // float mid = float(vect[midVal - 1] + vect[midVal]);
            // cout<<mid/2<< "\n";
            cout<<float(float(vect[midVal - 1] + vect[midVal])/2)<<"\n";
        }
    }

}
void median(vector<char> s,vector<int> X) {
    vector<char>::iterator its;
    unsigned short size = 0;
    vector<int>vect;
    unsigned int med = 0;
    for(int i = 0; i<s.size();i++){
        if(s[i] == 'r'){
            if(vect.size() == 0){
                cout<<"Wrong!\n";
            }
            else{
                if(find(vect.begin(), vect.end(), X[i]) != vect.end()){
                    vect.erase(find(vect.begin(), vect.end(), X[i]));
                    // debug
                    // printVect(vect);
                    // cout<<vect.size()<<" size\n";
                    printMedian(vect);
                }
                else{

                    cout<<"Wrong!\n";
                }
            }
        }
        else if(s[i] == 'a'){
            vect.push_back(X[i]);
            sort(vect.begin(),vect.end());
            //debug
            // printVect(vect);
            printMedian(vect);
        }
        else{
            cout<<"Wrong!\n";
        }
    }
    return;
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;

	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}

	median(s,X);
	return 0;
}
