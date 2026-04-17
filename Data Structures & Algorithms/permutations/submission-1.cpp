class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<int> used;

    void backtrack(vector<int>& nums){
        if(current.size()==nums.size()) {result.push_back(current);return;}
        for(int i=0; i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            current.push_back(nums[i]);
            backtrack(nums);
            used[i]=0;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        backtrack(nums);
        return result;
    }
};
