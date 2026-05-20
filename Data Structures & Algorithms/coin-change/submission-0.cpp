class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int n=1;n<=amount;n++){
            for(int i=0;i<coins.size();i++){
                if(n>=coins[i] && dp[n-coins[i]] != INT_MAX){
                    dp[n] = min(dp[n], dp[n-coins[i]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};
