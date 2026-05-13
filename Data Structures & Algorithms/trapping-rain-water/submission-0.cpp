class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref(n), suff(n); 
        for(int i=0;i<n;i++){
            if(i==0){
                pref[i] = height[i];
            }else{
                pref[i] = max(pref[i-1], height[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                suff[i] = height[i];
            }else{
                suff[i] = max(suff[i+1], height[i]);
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res += min(pref[i], suff[i])-height[i];
        }
        return res;
    }
};
