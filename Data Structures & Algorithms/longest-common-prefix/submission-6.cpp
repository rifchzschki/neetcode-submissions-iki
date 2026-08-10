class Solution {
public:
    unordered_map<string, int> mp;
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int j=1;j<strs.size();j++){
            int i = 0;
            while(strs[j][i] && prefix[i] && strs[j][i] == prefix[i]){
                i++;
            }
            if(!i){
                prefix="";
                break;
            }
            prefix = prefix.substr(0,i);
        }
        return prefix;
    }
};