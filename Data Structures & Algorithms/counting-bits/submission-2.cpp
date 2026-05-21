class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(uint32_t i=0;i<=n;i++){
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};
