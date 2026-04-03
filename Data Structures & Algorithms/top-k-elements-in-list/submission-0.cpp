class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;


        vector<pair<int,int>> v;

        for(auto it: mp)
            v.push_back({it.second,it.first});

        sort(v.begin(),v.end());


        vector<int> res;

        int n=v.size()-1;

        while(res.size()<k && n>=0){
            res.push_back(v[n].second);
            n--;
        }

        return res;        
    }
};
