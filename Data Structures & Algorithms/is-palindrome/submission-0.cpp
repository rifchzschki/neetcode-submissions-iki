class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());
        cout << s << endl;
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(tolower(s[i])!=tolower(s[n-i-1])) return false;
        }
        return true;
    }
};
