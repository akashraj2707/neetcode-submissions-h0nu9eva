class Solution {
    int []dx = {1,0,-1,0};
    int []dy = {0,1,0,-1};

    public boolean isValid(int m,int n,int i,int j){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    public int dfs(int[][] grid, int[][] vis,int m,int n,int i,int j){
        if(vis[i][j]==1)
            return 0;
        
        vis[i][j] = 1;
        int i2,j2;
        int res=1;
        for(int x =0 ;x<4; x++){
            i2 = i  + dx[x];
            j2 = j  + dy[x];
            
            if(!isValid(m,n,i2,j2))
                continue;
        
            if(grid[i2][j2]==1){
                res+= dfs(grid,vis,m,n,i2,j2);
            }
        }    

        return res;
    }

    public int maxAreaOfIsland(int[][] grid) {
            int m= grid.length;
            int n = grid[0].length;
            int res=0;

            int[][] vis = new int[m][n];

            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    vis[i][j]=0;

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1 && vis[i][j]==0)
                        res = Math.max(res,dfs(grid,vis,m,n,i,j));
                }
            }

            return res;
       
    }
}
