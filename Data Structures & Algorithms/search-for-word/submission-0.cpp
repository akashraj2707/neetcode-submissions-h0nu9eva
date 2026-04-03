class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int vis[1001][1001];

    bool isValid(int i,int j,int m, int n){
        return !(i< 0 || j< 0 || i>=m || j >=n);
    }

    bool dfs(int i,int j,vector<vector<char>>& board,string word,string temp){
        if(vis[i][j]==1)
            return false;

        vis[i][j]=1;
        temp+= board[i][j];

        if(word == temp)
            return true;

        int x2,y2;
        bool res=false;
        for(int x=0;x<4;x++){
            x2 = dx[x] + i;
            y2 = dy[x] + j;

            if(isValid(x2,y2,board.size(),board[0].size())){
                res|= dfs(x2,y2,board,word,temp);
            }

            if(res)
                break;
        }

        vis[i][j]=0;
        
        temp.pop_back();

        return res;    
    }

    void visited(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                vis[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                visited(board);
                if(dfs(i,j,board,word,""))
                    return true;
            }

        return false;    

    }   
};
