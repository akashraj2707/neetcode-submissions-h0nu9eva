class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=1;

        unordered_map<int,int> mp;
        int ctr=0,temp;

        for(auto it:nums)
            mp[it]=1;

        for(int i=0;i<nums.size();i++){
            temp = nums[i];
            ctr = 1; 
            while(mp.find(temp-1)!=mp.end()){
               
                ctr += mp[temp-1];
                mp.erase((temp-1));
                temp--;
                mp[nums[i]]=ctr;
            }
            cout<< nums[i]<<' '<< ctr<<'\n';
            
            ans = max(ans,ctr);
        }

        return ans;

        
    }
};
