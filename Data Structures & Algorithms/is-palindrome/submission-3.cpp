class Solution {
public:
    bool isPalindrome(string s) {
        // 2ms, 143.3MB
        // s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());
        // cout << s << endl;
        // int n = s.size();
        // for(int i=0;i<n/2;i++){
        //     if(tolower(s[i])!=tolower(s[n-i-1])) return false;
        // }
        // return true;

        // 2ms, 142.5MB
        // int i=0, j=s.size()-1;
        // while(i<j){
        //     while(!isalnum(s[i])) i++;
        //     while(!isalnum(s[j])) j--;
        //     if(i<j){
        //         if(tolower(s[i])!=tolower(s[j])) return false;
        //         else{
        //             i++;
        //             j--;
        //         }
        //     }
        // }
        // return true;

        int i = 0, j = (int)s.size() - 1;

        while (i < j) {
            unsigned char a = s[i], b = s[j];

            if (!isalnum(a)) { i++; continue; }
            if (!isalnum(b)) { j--; continue; }

            if (tolower(a) != tolower(b)) return false;
            i++; j--;
        }
        return true;
    }
};
