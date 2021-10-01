/*
Soln :
  1. Make heap
  2. pop 1st element
  3.pop the 2nd element
  4. insert the their sum to the heap
*/
int cookies(int k, vector<int> A) {
    int min1, min2,cnt = 0,retVal;
    make_heap(A.begin(), A.end(),greater<int>());
    while(A.front()<k && A.size()>1){

        cout<<"\n";
        min1 = A.front();
        pop_heap(A.begin(), A.end(), greater<int>());
        A.pop_back();
        min2 = A.front();
        pop_heap(A.begin(), A.end(), greater<int>());
        A.pop_back();
        A.push_back(min1+(2*min2));
        push_heap(A.begin(), A.end(), greater<int>());
        cnt++;
        // for(auto &it:A){
        //     cout<<it<<" ";
        // }
    }
    if(cnt<=0 && A.front()>k){
        retVal = cnt;
    }
    else if(cnt <=0 || A.front()<k){
        retVal = -1;
    }
    else{
        retVal = cnt;
    }
    return retVal;
}
