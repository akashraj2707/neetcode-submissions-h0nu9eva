class Solution {
public:

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool isValid(int x,int y,vector<vector<int>> &vis){
        if( x< 0 || y<0 || x>=vis.size() || y>= vis[0].size())
            return false;

        return true;    
    }
    void bfs(int i,int j, vector<vector<int>> &vis,vector<vector<char>>& grid){

        queue<pair<int,int>> q;

        q.push({i,j});
        vis[i][j]=1;
        int x,y;
        while(q.size()>0){

            auto it = q.front();
            q.pop();
            for(int k=0;k< 4 ;k++){
                x = dx[k]+it.first;
                y = dy[k]+it.second;

                if(isValid(x,y,vis)){
                    if(vis[x][y]==0 && grid[x][y]=='1'){
                        q.push({x,y});
                        vis[x][y]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int> (n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    res++;
                }
            }
        }

        return res;
    }
};
