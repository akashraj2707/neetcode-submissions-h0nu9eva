class Solution {
    int []dx = {1,0,-1,0};
    int []dy = {0,-1,0,1};
    private boolean isValid(int i,int j, int m,int n){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    private boolean dfs(String word,char[][] board,boolean[][] vis,int i,int j,int ind){
        
        if(ind == word.length()-1)
            return true;
        
        int m = board.length;
        int n = board[0].length;
        vis[i][j]=true;

        int x,y;
        for(int k=0;k<4;k++){
            x = dx[k] + i;
            y = dy[k] + j;

            if(isValid(x,y,m,n)){
                
                if((!vis[x][y])&& word.charAt(ind+1) == board[x][y]){
                    if(dfs(word,board,vis,x,y,ind+1)){
                        vis[i][j]=false;
                        return true;
                    }
                        
                }
            }
        }

        vis[i][j]=false;
        return false;
    }
    public List<String> findWords(char[][] board, String[] words) {
        int n = words.length;
        int x = board.length;
        int y = board[0].length;
        boolean [][]vis= new boolean[x][y];
        boolean found;
        List<String> res= new ArrayList<>();
        for(int i=0;i<n;i++){
            found = false;
            for(int j=0;j<x;j++){
                for(int k=0;k<y;k++){
                    if(board[j][k]==words[i].charAt(0)){
                        if(dfs(words[i],board,vis,j,k,0)){
                            found = true;
                            break;
                        }
                    }
                }

                if(found)
                    break;
            }
            if(found)    
                res.add(words[i]);
        }

        return res;
    }
}
