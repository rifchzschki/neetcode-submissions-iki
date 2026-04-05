class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string val: tokens){
            if(val == "+" ||val == "/" ||val == "*" ||val == "-" ){
                int op1 = stoi(st.top());st.pop();
                int op2 = stoi(st.top());st.pop();
                if(val == "+"){
                    st.push(to_string(op1+op2));
                }else if(val == "-"){
                    st.push(to_string(op2-op1));
                }else if(val == "*"){
                    st.push(to_string(op1*op2));
                }else if(val == "/"){
                    st.push(to_string(op2/op1));
                }
            }else{
                    st.push(val);
            }
            
        }
    if(st.size()==1) return stoi(st.top());
    else cout<<"invalid condition"<<endl;
    }
};
