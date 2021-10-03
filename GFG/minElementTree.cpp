/*
soln:
    1, traverse the tree till you get the leftmost element
*/

class Solution{
    public:
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    bool isMaxHeap(int a[], int n)
    {
        bool flag = true;
        for(int i = 0; i<n; i++){
            if(left(i)<n){
                if( (a[left(i)]>a[i])){
                    flag = false;
                    break;
                }
            }
            if(right(i)<n){
                if(a[right(i)] > a[i]){
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};
