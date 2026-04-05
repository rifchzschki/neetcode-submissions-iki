class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        map<char, int> mp;
        for(char c: s){
            mp[c]++;
        }
        for(char c: t){
            mp[c]--;
        }
        for(auto m: mp){
            if(m.second!=0)return false;
        }
        return true;
    }
};
