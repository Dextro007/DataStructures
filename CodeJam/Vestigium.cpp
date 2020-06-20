#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k,r,c;
    //set<int> check_num;
    set<int> row_set;
    set<int> col_set;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        int **arr = new int*[n];
        for(int j=0; j<n; j++){
            arr[i] = new int[n];
        }
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                cin>>arr[row][col];
            }
        }
        k=0;r=0;c=0;
        cout<<"hey\n";                                                          //Debug
        for(int row=0; row<n; row++){
          for(int col=0; col<n; col++){
            //check_num.insert(arr[row][col]);
            row_set.insert(arr[row][col]);
            col_set.insert(arr[col][row]);
            if(row == col)
              k += arr[row][col];
          }
          if(n-row_set.size() !=0)
            r++;
          if(n-col_set.size() != 0)
            c++;
          row_set.clear();
          col_set.clear();
        }

        cout<<"Case #"<<i<<": "<<k<<" "<<r<<" "<<c;
        for(int row = 0; row<n; row++){
          delete [] arr[row];
        }
        delete [] arr;
    }
    return 0;
}
