class Solution {
public:
    vector<int> curr;
    int currSum=0;
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int target, int start){
        if(curr.size()==4){
            if(currSum==target) ans.push_back(curr);
            return;
        }
        if(nums.size()-start < 4-curr.size()) return;
        for(int i=start; i<nums.size();i++){
            if(i>start && nums[i-1]==nums[i]) continue;
            if(curr.size()<4 && currSum+nums[i]>target && nums[i]>0) break;
            curr.push_back(nums[i]);
            currSum+=nums[i];
            backtrack(nums, target, i+1);
            currSum-=nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0);
        return ans;
    }
};