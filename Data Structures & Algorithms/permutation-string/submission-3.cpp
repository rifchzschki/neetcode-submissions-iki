class Solution {
public:
    void debug(
        unordered_map<char, int> mp,
        unordered_map<char, int> mp_copy
    ){
        cout << "s2" << endl;
        for(const auto a: mp_copy){
            cout<<a.first<<" "<<a.second<<endl;
        }
        cout << "s1" << endl;
        for(const auto a: mp){
            cout<<a.first<<" "<<a.second<<endl;
        }
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> mp_copy;
        int window_size = s1.length();

        for(int i=0;i<window_size;i++){
            mp[s1[i]]++;
            mp_copy[s2[i]]++;
        }

        if(mp==mp_copy) return true;
        int j=0;
        while(j+window_size<s2.length()){
            mp_copy[s2[j+window_size]]++;
            if(mp_copy[s2[j]]<=1){
                mp_copy.erase(s2[j]);
            }else{
                mp_copy[s2[j]]--;
            }
            debug(mp, mp_copy);
            if(mp==mp_copy) return true;
            j++;
        }
        return false;

        
    }
};
