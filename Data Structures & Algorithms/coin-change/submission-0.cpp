class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int int_max = 1e9 + 7 ;
        vector<int> dp(amount+1, int_max);

        dp[0] = 0;
        int res;
        for(int i=1;i<=amount;i++){
            
            for(int j=0;j<coins.size();j++){
                if(coins[j]> i){
                    continue;
                }

                dp[i] = min(dp[i],1+dp[i-coins[j]]);   
            }

            cout<< dp[i];
        }

        return (dp[amount] == int_max) ? -1 : dp[amount];
        
    }
};
