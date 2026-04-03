class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]*prefix[i-1];
        }

        vector<int> revPrefix(n,0);
        revPrefix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            revPrefix[i]= nums[i]*revPrefix[i+1];

        vector<int> res(n,0);

        int left,right;
        for(int i=0;i<nums.size();i++){
            left=1,right=1;

            if(i!=0)
                left = prefix[i-1];
            if(i!=n-1)
                right = revPrefix[i+1];    

            res[i]= left * right;     
        }    

        return res;
    }
};
