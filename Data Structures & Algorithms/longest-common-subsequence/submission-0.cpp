class Solution {
public:
    int dp[1002][1002];
    int helper(string s1,string s2,int i,int j){

        if(i<0 || j< 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int res =0;
        
        if(s1[i]==s2[j])
            res = 1+ helper(s1,s2,i-1,j-1);
        else res = max(helper(s1,s2,i,j-1),helper(s1,s2,i-1,j));
        
        return dp[i][j]=res;    


    }
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        for(int i=0;i<t1.size();i++)
            for(int j=0;j<t2.size();j++)
                dp[i][j]=-1;

        return helper(t1,t2,m-1,n-1);        
    }
};
