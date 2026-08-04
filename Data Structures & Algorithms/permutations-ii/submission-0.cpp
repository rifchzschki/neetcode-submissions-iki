class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    vector<int> used;

    void backtrack(vector<int>& nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;

            used[i]=1;
            curr.push_back(nums[i]);
            backtrack(nums);
            curr.pop_back();
            used[i]=0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<int>(nums.size(), 0);
        backtrack(nums);
        return ans;
    }
};