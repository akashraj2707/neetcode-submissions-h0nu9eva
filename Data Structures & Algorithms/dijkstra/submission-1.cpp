class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        
        vector<int> vis(n,0);

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        
        vector<pair<int,int>> graph[1002];
        int x,y,w;
        for(int i=0;i<edges.size();i++){
            
            x = edges[i][0];
            y = edges[i][1];
            w = edges[i][2];

            graph[x].push_back({y,w});
        }

        pq.push({0,src});
        unordered_map<int,int> res;
        for(int i=0;i<n;i++)
            res[i]= -1;
        while(pq.size()>0){
            auto it = pq.top();
            pq.pop();
            if(vis[it.second]==1)
                continue;

            x = it.second;
            w = it.first;
            vis[x]=1;
            
            res[x] = it.first;
            for(auto node:graph[x]){
                if(vis[node.first]==0)
                    pq.push({w+node.second, node.first});
            }

        }

        

        return res;
        
    }
};
