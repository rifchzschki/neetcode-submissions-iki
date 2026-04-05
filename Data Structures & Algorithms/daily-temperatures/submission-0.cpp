class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res;

        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top().second <= temperatures[i]) st.pop();
            if(st.empty()){
                res.push_back(0);
            }else{
                res.push_back(abs(st.top().first-i));
            }
            st.push({i, temperatures[i]});
        }
        reverse(res.begin(), res.end());

        return res;
    }
};