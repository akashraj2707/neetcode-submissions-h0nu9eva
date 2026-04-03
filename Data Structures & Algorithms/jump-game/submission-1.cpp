class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        if(nums[0]==0)
           return false;

        int pre=nums[0];

        for(int i=1;i<nums.size();i++){
            pre--;

            if(pre<0)
                return false;

            pre = max(pre, nums[i]);    

        }


        return true;


        
    }
};
