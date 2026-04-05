class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alph(95,-1);
        int i=0,j=0,res=0;

        while(j<s.size()){
            int idx = alph[s[j]-' '];
            if(idx!=-1 && idx>=i){
                res = max(res, j-i);
                i = idx+1;
            }
            alph[s[j]-' '] = j;
            j++;
        }
        return max(res,j-i);
    }
};
