class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0, res=INT_MIN;
        for(int& n: nums){
            curr+=n;
            if(n>curr){
                curr = n;
            }
            if(curr>res){
                res = curr;
            }
        }
        return res;
    }
};
