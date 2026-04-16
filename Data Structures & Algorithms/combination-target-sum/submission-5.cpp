class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>&nums, int start, int sum, const int target){
        if(sum==target) {
            result.push_back(current);
            return;
        }

        for(int i=start; i<nums.size(); i++){
            if(sum+nums[i]<=target){
                current.push_back(nums[i]);
                backtrack(nums, i, sum+nums[i], target);
                current.pop_back();
            }else{
                continue;
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, 0,target);
        return result;
    }
};
