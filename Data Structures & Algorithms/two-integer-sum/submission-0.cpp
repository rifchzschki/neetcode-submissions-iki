class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp; //diff, index
        for(int i=0;i<nums.size();i++){
            auto it = mp.find(nums[i]);
            if(it!=mp.end()){
                return vector<int>{it->second, i};
            }
            mp[target-nums[i]] = i;
        }
        auto it = mp.find(nums[nums.size()-1]);
        if(it!=mp.end()){
            return vector<int>{it->second, nums.size()-1};
        }
        return vector<int>{}; // never
    }
};
