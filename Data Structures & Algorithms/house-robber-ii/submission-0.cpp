class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return nums[0];

        vector<vector<int>> dp(2,vector<int> (n,0));
        int res;

        res = max(nums[0],nums[1]);

        dp[0][1] = nums[1];
        int x,y;
        
        for(int i=2;i<nums.size();i++){
           dp[0][i] = max(dp[0][i-1], dp[0][i-2] + nums[i]);
           res = max(res,dp[0][i]);
        }

        dp[1][0] = nums[0];
        dp[1][1] = max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++){
            dp[1][i] = max(dp[1][i-1], dp[1][i-2] + nums[i]);
            res = max(res,dp[1][i]);
        }


        return res;
    }
};
