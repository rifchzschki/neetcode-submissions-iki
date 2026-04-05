class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int val: nums){
            mp[val]++;
        }
        vector<pair<int, int>> vp(mp.begin(), mp.end());
        sort(vp.begin(), vp.end(), [](auto &a, auto &b){return a.second>b.second;});
        vector<int> res;
        for(auto m: vp){
            res.push_back(m.first);
            k--;
            if(!k) break;
        }
        return res;
    }
};
