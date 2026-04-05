class Solution {
public:
    unordered_map<char, char> mp = {
        {')','('},
        {'}','{'},
        {']','['},
    };
    bool isValid(string s) {
        stack<int> st;
        for(char c:s){
            if(!st.empty()&&st.top()==mp[c]){
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.size()==0;
    }
};
