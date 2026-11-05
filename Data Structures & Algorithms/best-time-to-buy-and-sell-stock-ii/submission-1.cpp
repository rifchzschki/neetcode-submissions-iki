class Solution {
public:
    int performRec(vector<int>& prices, vector<vector<int>>& dp, bool bought, int i){
        if(prices.size()==i) return 0;
        if(dp[i][bought]!=-1) return dp[i][bought];

        int res = performRec(prices, dp, bought, i+1);

        if(bought){
            res = max(res, performRec(prices, dp, !bought, i+1)+prices[i]);
        }else{
            res = max(res, performRec(prices, dp, !bought, i+1)-prices[i]);
        }
        dp[i][bought] = res;
        return res;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (prices.size(), vector<int>(2, -1));
        return performRec(prices,dp,0,0);
    }
};