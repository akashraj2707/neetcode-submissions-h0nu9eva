class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<String , Integer> mp1 = new HashMap<>();
        Set<String> st = new HashSet<>();

        List<Integer> res = new ArrayList<>();

        String key;
        int value;
        for(int i=0;i<s.length();i++){
            
            key = s.charAt(i)+"";
            value = 0;
            if(mp1.containsKey(key))
                value = mp1.get(key);

            mp1.put(key,value+1);     
        }

        int cur=0;
        for(int i=0; i<s.length();i++){
            cur++;
            key = s.charAt(i)+"";
            value = mp1.get(key);

            if(!st.contains(key))
                st.add(key);

            if(value == 1){
                st.remove(key);
            }

            if(st.size()==0){
                res.add(cur);
                cur=0;
            }

            mp1.put(key,value-1);
        }

        return res;

    }
}
