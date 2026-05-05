class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len+1);
        dp[0] = 0; 
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for(int i=3;i<=len;i++){
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[len];

    }
};
