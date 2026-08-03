class Solution {
public:

    int total = 0, xorSub=0;

    void backtract(vector<int>& nums, int start){
        total+=xorSub;
        for(int i=start;i<nums.size();i++){
            xorSub^=nums[i];
            backtract(nums, i+1);
            xorSub^=nums[i];
        }
    }

    int subsetXORSum(vector<int>& nums) {
        backtract(nums, 0);
        return total;
    }
};