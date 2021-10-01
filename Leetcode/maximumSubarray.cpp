class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = nums[0];
        int maxTillNow = nums[0];
        // start with 1 else curr max in 1st hit will be twice the 1st element
         for(int i = 1; i<nums.size(); i++){
             //currmax is the local max which might get replaced with
             currMax = max(nums[i], nums[i]+currMax);
             // if
             maxTillNow = max(currMax, maxTillNow);
         }
        return maxTillNow;
    }

};
