class Solution {
public:
    int countSubstrings(string s) {
        int res=0;

        int i=0;
        int n= s.size();

        for(int i=0;i<s.size();i++){
            // odd length

            
            int j =i;
            int k =i;
            while(j >= 0 && k< n){
                
                if(s[j] == s[k]){
                    res ++;
                    j--;
                    k++;
                }else break;
            }

            // even length
            j = i;
            k = i+1;

            while(j >= 0 && k< n){
                if(s[j] == s[k]){
                    res ++;
                    j--;
                    k++;
                }else break;
            }
        }
        return res;


    }
};
