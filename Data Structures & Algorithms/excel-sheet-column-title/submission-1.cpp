class Solution {
public:
    //recursion
    string convertToTitle(int columnNumber) {
        if(columnNumber<=26){
            string res(1,static_cast<char>(columnNumber+64));
            return res;
        }
        int it=columnNumber/26;
        columnNumber%=26;
        string backC(1, static_cast<char>(columnNumber+64));
        return convertToTitle(it) + backC;
    }
};