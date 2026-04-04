class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int []dp = new int[n];

        for(int i=0;i<n;i++){
            dp[i]=n+1;
        }
        int jump;
        dp[0]=0;
        for(int i=0;i<nums.length;i++){
            jump = nums[i];
            for(int j=i+1;j<=Math.min(n-1,i+jump);j++)
                dp[j]=Math.min(dp[j],dp[i]+1);
        }
        return dp[n-1];
    }
}
