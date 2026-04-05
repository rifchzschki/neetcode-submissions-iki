class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMult(n);
        vector<int> suffMult(n);
        // build prefmult
        for(int i=0;i<n;i++){
            if(i>0){
                prefMult[i]=prefMult[i-1]*nums[i];
            }else{
                prefMult[i] = nums[i];
            }
        }

        // build suffmult
        for(int i=n-1;i>=0;i--){
            if(i<n-1){
                suffMult[i]=suffMult[i+1]*nums[i];
            }else{
                suffMult[i] = nums[i];
            }
        }

        // compute
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(i==0){
                res[i] = suffMult[i+1];
            }else if(i==n-1){
                res[i] = prefMult[i-1];
            }else{
                res[i] = prefMult[i-1]*suffMult[i+1];
            }
        }
        return res;

    }
};
