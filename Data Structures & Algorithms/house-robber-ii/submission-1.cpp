class Solution {
public:
    int robSolve(vector<int>& nums, int l, int r) {
        nums[l+1] = max(nums[l], nums[l+1]);
        for(int i=l+2;i<r;i++) nums[i] = max(nums[i-1], nums[i] + nums[i-2]);
        return nums[r-1];
    }

    int rob(vector<int>& nums){
        vector<int> nums2(nums.begin(), nums.end());
        return max(robSolve(nums, 0, nums.size()-1),robSolve(nums2, 1, nums2.size()));
    }

};
