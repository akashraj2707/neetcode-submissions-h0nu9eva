class Solution {
    public int jump(int[] nums) {
       
        if(nums.length==1)
            return 0;    
        
        int l = 0;
        int r = nums[0];
        int nextR=0;
        int count = 1; 
        while(r<nums.length-1){
            while(l<=r){
                nextR = Math.max(nextR,l+nums[l]);
                l++;
            }
            r = nextR;
            count++;
        }
        return count;
    }
}
