class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;

    void backtract(int n, int k, int start){
        if(k==curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            backtract(n, k, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtract(n, k, 1);
        return ans;      
    }
};