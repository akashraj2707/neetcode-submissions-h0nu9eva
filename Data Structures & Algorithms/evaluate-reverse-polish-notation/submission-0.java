class Solution {
    public int evalRPN(String[] tokens) {
        Deque<String> st = new ArrayDeque<>();

        for(int i=0;i<tokens.length;i++){
            if(tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*") || tokens[i].equals("/")){
                
                int y = Integer.valueOf(st.peek());
                st.pop();
                int x = Integer.valueOf(st.peek());
                st.pop();

                if(tokens[i].equals("+"))    
                    st.push(String.valueOf(x+y));
                if(tokens[i].equals("-"))    
                    st.push(String.valueOf(x-y));
                if(tokens[i].equals("*"))    
                    st.push(String.valueOf(x*y));
                if(tokens[i].equals("/"))    
                    st.push(String.valueOf(x/y));


            }else st.push(tokens[i]);
        }

        return Integer.valueOf(st.peek());
    }
}
