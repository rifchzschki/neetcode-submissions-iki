class Solution {
public:
    string curr;
    vector<string> ans;

    void backtrack(int n, int open, int close){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }

        // case tambah (
        // - kalau ( < n
        // case tambah )
        // - kalau ( > )

        if(open < n ){
            curr.push_back('(');
            backtrack(n, open+1, close);
            curr.pop_back();
        }

        if(open > close){
            curr.push_back(')');
            backtrack(n, open, close+1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        curr = "";
        backtrack(n, 0, 0);
        return ans;
    }
};
