class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> st;

        for(int i=0;i<nums.size();i++){
            if(st.find(target-nums[i])!=st.end())
                return {st[target-nums[i]],i};

            st[nums[i]] = i;    
        }

        return {-1,-1};
    }
};
