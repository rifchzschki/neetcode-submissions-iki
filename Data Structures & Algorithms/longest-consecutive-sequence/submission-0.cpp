class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int val: nums){
            st.insert(val);
        }
        vector<int> v(st.begin(), st.end());
        
        int res=0, counter=1;
        for(int i=0; i<v.size();i++){
            if(i>0){
                if(v[i] - v[i-1] == 1){
                    counter ++;
                }else{
                    counter = 1;
                }
            }
            res = max(res, counter);
        }
        return res;
    }
};
