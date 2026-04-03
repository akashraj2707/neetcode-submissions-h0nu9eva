class Solution {
public:
    // 4 4 4 1 4 5 5 1 1
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int res=0;
        int n=s.size();
        vector<int> dp(n,0);

        dp[0]=1;
        string temp;
        for(int i=1;i<n;i++){
            temp = "";

            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]== '2')
                    dp[i] = i>1 ? dp[i-2] : 1;
                else return 0;   

                continue; 
            }
            // d d d a a
            // d d d o

            dp[i] = dp[i-1];

            if(s[i-1]=='1'){
                dp[i] += i>1 ?(dp[i-2]):1;
            }else if(s[i-1]=='2' && (s[i] <'7')){
                dp[i] += i>1 ?(dp[i-2]):1;
            }    
            
            

        }

        return dp[n-1];
    }
};
