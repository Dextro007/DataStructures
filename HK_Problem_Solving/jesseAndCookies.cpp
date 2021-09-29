/*
Soln :
  1. Make heap
  2. pop 1st element
  3.pop the 2nd element
  4. insert the their sum to the heap
*/
int cookies(int k, vector<int> A) {
    int min1, min2,cnt = 0,retVal;
    make_heap(A.begin(), A.end());
    sort_heap(A.begin(), A.end());
    vector<int>::iterator upper;
    while(A.front()<k && A.size()>1){
        // for(auto &it : A){
        //     cout<<it<<" ";
        // }
        cout<<"\n";
        min1 = *(A.begin());
        min2 = *(A.begin()+1);
        A.erase(A.begin(),A.begin()+2);
        upper = upper_bound(A.begin(), A.end(), (min1+2*min2));
        A.insert(upper, (min1+2*min2));
        cnt++;
    }
    if(cnt>0){
        retVal = cnt;
    }
    else{
        retVal = -1;
    }
    return retVal;
}
