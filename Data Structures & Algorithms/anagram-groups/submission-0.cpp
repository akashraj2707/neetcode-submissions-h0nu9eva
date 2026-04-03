class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            vector<int> v(26,0);

            for(auto it: strs[i]){
                v[it-'a']++;
            }
            mp[v].push_back(strs[i]);
        }

        vector<vector<string>> res;


        for(auto it: mp){
            res.push_back(it.second);
        }

        return res;


    }
};
