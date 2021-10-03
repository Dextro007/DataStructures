/*
Prblm : check if the given array is
Soln : In Heap Left child is at 2*i +1 and right child at 2*i+2
      1. Get the left child
      2. Get the right child
      3. check if both of them is less than the root (i)
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
