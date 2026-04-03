class Solution {
public:

    int dp[1001][1001];

    bool helper(string s,int i, string temp,int j,set<string> &store){

        if(j==s.size()){
            if(temp.size()==0)
                return true;

            if(store.find(temp)!=store.end())
                return true;

            return false;        
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        temp+=s[j];

        bool res=false;
        if(store.find(temp)!=store.end()){
            res = helper(s,j+1,"",j+1,store);
        }

        res = (res || helper(s,i,temp,j+1,store));

        return dp[i][j]=res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> store;

        for(auto it:wordDict)
            store.insert(it);

        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++)
                dp[i][j]=-1;
        }

        return helper(s,0,"",0,store);

    }
};
