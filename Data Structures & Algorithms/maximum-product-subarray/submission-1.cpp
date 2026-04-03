class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        int maxSoFar=nums[0];
        int minSoFar=nums[0];

        int temp;
        for(int i=1;i<nums.size();i++){
            if(maxSoFar == 0 && minSoFar == 0){
                res = max(res,nums[i]);
                maxSoFar = nums[i];
                minSoFar = nums[i];
            }else {
                temp = max(maxSoFar*nums[i],max(nums[i],minSoFar*nums[i]));
                minSoFar = min(maxSoFar*nums[i],min(nums[i],minSoFar*nums[i]));
                maxSoFar = temp;
                res = max(maxSoFar,res);

                cout<< maxSoFar << ',' << minSoFar <<'\n';
            }
        }

        return res;
    }
};
