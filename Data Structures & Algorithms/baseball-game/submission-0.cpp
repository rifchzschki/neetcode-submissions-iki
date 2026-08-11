class Solution {
public:
    stack<int> st;
    int calPoints(vector<string>& operations) {
        int curr=0;
        for(string &op: operations){
            if(op=="+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
                curr+=(a+b);
            }else if(op=="D"){
                curr+=(st.top()*2);
                st.push(st.top()*2);
            }else if(op=="C"){
                curr-=(st.top());
                st.pop();
            }else{
                curr+=(stoi(op));
                st.push(stoi(op));
            }
        }
        return curr;
    }
};