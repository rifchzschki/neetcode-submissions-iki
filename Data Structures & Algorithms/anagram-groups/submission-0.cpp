class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> mp;
        for(string s: strs){
            vector<char> strc(26,0);
            for(char c: s){
                strc[(c-'0')%26]++;
            }
            mp[strc].push_back(s);
        }

        vector<vector<string>> res;
        for(auto val: mp){
            res.push_back(val.second);
        }
        return res;
    }
};
