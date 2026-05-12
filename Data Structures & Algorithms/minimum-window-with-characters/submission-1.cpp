class Solution {
public:
    string minWindow(string s, string t) {
        if(!t.size()) return "";
        unordered_map<char, int> freq;
        unordered_map<char, int> curr;
        for(char c: t){
            freq[c]++;
        } 

        int cnt=0,l=0,r=0;
        pair<int,int> p={-1,-1};
        while(r<s.size()){
            curr[s[r]]++;
            if(freq.count(s[r])&&curr[s[r]]==freq[s[r]]){
                cnt++;
            }
            while(cnt==freq.size()){
                // shrink
                if(curr[s[l]]) curr[s[l]]--;
                if(freq.count(s[l]) && curr[s[l]]<freq[s[l]]) cnt--;
                
                if(p.first==-1 || (r-l < p.second-p.first)){
                    p = {l,r};
                }
                l++;
            }
            r++;
        }
        return p.first==-1?"":s.substr(p.first, p.second-p.first+1);
    }
};
