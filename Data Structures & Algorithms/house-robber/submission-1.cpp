class Solution {
public:
    int rob(vector<int>& nums) {
        int res=0;
        int n=nums.size();

        if(n==1)
            return nums[0];

        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1]=nums[1];

        res=max(dp[0],dp[1]);
        dp[1]=res;
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1], (nums[i] + dp[i-2]));

            res = max(res,dp[i]);
            cout<< dp[i]<<' '; 
        }

        return res;
    }

    // 5,1,2,10,6, 2,  7, 9,3,1
    // 5 5 7 15 15 17  22 26 26 27 
};
