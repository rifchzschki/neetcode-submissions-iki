class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=1;i<nums.size()-1;i++){
            int j=0,k=nums.size()-1;
            int target = nums[i]*(-1);
            while(j<k && i!=j && i!=k){
                if(target == (nums[j]+nums[k])){
                    res.insert({nums[i], nums[j], nums[k]});
                    j++;k--;
                }else if(target > (nums[j]+nums[k])){ // naikin (++j)
                    j++;
                }else{
                    k--;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
