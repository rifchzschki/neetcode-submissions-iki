class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& cand, int start, int target){
        if(target==0){
            result.push_back(current);
            return;
        }

        for(int i=start;i<cand.size();i++){
            if(i>start && cand[i]==cand[i-1]) continue;
            if(target-cand[i]>=0){
                current.push_back(cand[i]);
                backtrack(cand, i+1, target-cand[i]);
                current.pop_back();
            }else{
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return result;
    }
};
