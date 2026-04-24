class Solution {

    int[] dx = {1,0,0,-1};
    int[] dy = {0,1,-1,0};

    boolean isValid(int i,int j,int n,int m){
        return !(i<0 || j<0 || i>=n || j>=m);
    }
    private int dfs(int [][]matrix, int [][]vis,int i,int j){
        if(vis[i][j]!=0)
            return vis[i][j];

        int x,y;
        int res=0;
        int n = matrix.length,  m = matrix[0].length;

        for(int k=0;k<4;k++){

            x = i + dx[k];
            y = j + dy[k];

            if(isValid(x,y,n,m)){
                if(matrix[x][y] > matrix[i][j]){
                    if(vis[x][y] ==0)
                        vis[x][y] = dfs(matrix,vis,x,y);
                    
                    res = Math.max(res,vis[x][y]);
                }
            }
            
        }
        return vis[i][j] = 1 + res;
    }
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp= new int [n][m];

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=0;

        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dp[i][j]==0)
                    res = Math.max(res,dfs(matrix,dp,i,j));     


        return res;

    }
}
