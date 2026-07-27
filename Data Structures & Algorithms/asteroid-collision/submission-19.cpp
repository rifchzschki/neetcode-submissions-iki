class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int& ast : asteroids){
            while(!st.empty() && (st.back()>0 && ast<0) && abs(st.back())<=abs(ast)){
                int backVal = st.back();
                st.pop_back();
                if(abs(backVal)==abs(ast)){
                    ast = 0;
                    break;
                }
            }
            if(ast && (st.empty() || !(st.back()>0 && ast<0))){
                st.push_back(ast);
            }

        }
        return st;
    }
};


