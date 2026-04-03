class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int maxSub = 0;
        for(int i=0;i<nums.size();i++){
            maxSub+=nums[i];

            if(maxSub < 0)
                maxSub =0;
            else maxSum = max(maxSum, maxSub);    

            maxSum = max(maxSum, nums[i]);


        }

        return maxSum;
    }
};
