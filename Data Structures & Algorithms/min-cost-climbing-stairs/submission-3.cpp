class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        vector<int> dp(top+1); // define for cost for reach i floor
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2; i<=top;i++){
            if(i<top) dp[i]=cost[i];
            dp[i] += min(dp[i-1],dp[i-2]);
            cout << dp[i] << endl;
        }
        return dp[top];
    }
};
