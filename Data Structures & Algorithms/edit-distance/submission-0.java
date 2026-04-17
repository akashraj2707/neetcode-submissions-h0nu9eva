class Solution {
    public int solve(int[][] dp,String word1,String word2,int i,int j){

        if(i<0 && j<0)
            return 0;
        else if(i<0 || j<0){
            return 1+ Math.max(i,j);
        }        

        if(dp[i][j]!=-1)
            return dp[i][j];

        int res;
        int case1,case2,case3;
        if(word1.charAt(i)==word2.charAt(j)){
            res = solve(dp,word1,word2,i-1,j-1);
        }else{

        // insert A character
            case1 = 1+solve(dp,word1,word2,i,j-1);
        // delete A character
            case2 = 1+solve(dp,word1,word2,i-1,j);
        // replace A character
            case3 = 1+solve(dp,word1,word2,i-1,j-1);

            res = Math.min(case1,Math.min(case2,case3));
        }

        return dp[i][j]=res;
               
        
    }
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        int[][] dp = new int[m+1][n+1];

        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;

        return solve(dp,word1,word2,m-1,n-1); 

    }
}
