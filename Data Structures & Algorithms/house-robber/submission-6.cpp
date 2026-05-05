class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        nums[1] = max(nums[0], nums[1]);
        for(int i=2;i<len;i++) nums[i] = max(nums[i-1], nums[i] + nums[i-2]);
        return nums[len-1];

    }
};
