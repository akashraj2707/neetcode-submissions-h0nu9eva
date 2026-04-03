class Solution {
public:
    vector<int> graph[2005];

    void dfs(int node, vector<int> &vis){
        vis[node]=1;

        for(auto it: graph[node]){
            if(vis[it]==0)
                dfs(it,vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int res=0;
        for(int i=0;i<n+1;i++){
            graph[i].clear();
        }    

        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }


        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                res++;
                dfs(i,vis);
            }
        }

        return res;
    }
};
