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
// using balanced tree approach
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
