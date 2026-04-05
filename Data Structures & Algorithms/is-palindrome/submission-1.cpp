class Solution {
public:
    bool isPalindrome(string s) {
        // s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());
        // cout << s << endl;
        // int n = s.size();
        // for(int i=0;i<n/2;i++){
        //     if(tolower(s[i])!=tolower(s[n-i-1])) return false;
        // }
        // return true;
        int i=0, j=s.size()-1;
        while(i<j){
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;
            if(i<j){
                if(tolower(s[i])!=tolower(s[j])) return false;
                else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};
