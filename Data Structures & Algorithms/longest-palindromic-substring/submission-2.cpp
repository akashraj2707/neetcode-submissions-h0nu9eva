class Solution {
public:
    string longestPalindrome(string s) {
        int res=0,temp=0;

        int i=0;
        int n= s.size();
        int x,y;

        for(int i=0;i<s.size();i++){
            // odd length
            temp=0;
            
            int j =i;
            int k =i;
            while(j >= 0 && k< n){
                
                if(s[j] == s[k]){
                    temp++;
                    j--;
                    k++;
                }else break;
            }

            if( (2*temp-1) > res){
                x = j+1;
                y = k-1;
                res = 2*temp-1;
            }

            // even length
            j = i;
            k = i+1;
            temp=0;
            while(j >= 0 && k< n){
                if(s[j] == s[k]){
                    temp ++;
                    j--;
                    k++;
                }else break;
            }

            if( 2*temp > res){
                x = j+1;
                y = k-1;
                res = 2*temp;
            }
        }

        string ans;
        cout<< x<< ' '<<y;
        ans = s.substr(x,y+1 - x);


        return ans;
    }
};
