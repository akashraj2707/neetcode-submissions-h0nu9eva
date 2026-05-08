class Solution {


    public int[] maxSlidingWindow(int[] nums, int k) {
        
        Map<Integer,Integer> mp = new TreeMap<>();
        int sz=0;
        int key,value;
        List<Integer> res= new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            sz++;
            key = -nums[i];
            mp.put(key, mp.getOrDefault(key,0)+1);

            if(sz > k){
                key = -nums[i-k];
                value = mp.get(key);

                if((value - 1)==0)
                    mp.remove(key);
                else mp.put(key,value-1);  

                res.add(-mp.keySet().iterator().next());
            }else if(sz == k){
                res.add(-mp.keySet().iterator().next());
            }

            //
        }

        int[] arr = res.stream().mapToInt(Integer::intValue).toArray();

        return arr;
    }
}
