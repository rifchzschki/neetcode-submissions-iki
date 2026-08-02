class Solution {
public:
    //recursion
    string convertToTitle(int columnNumber) {
        if(columnNumber<=26){
            string res(1,static_cast<char>(columnNumber+64));
            return res;
        }
        string backC(1, static_cast<char>((columnNumber%26)+64));
        return convertToTitle(columnNumber/26) + backC;
    }
};