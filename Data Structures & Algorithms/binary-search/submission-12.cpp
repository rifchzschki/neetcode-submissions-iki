class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return (nums[0]==target) ? 0 : -1;
        int l=0,r=nums.size()-1, res=-1;
        bool found = false;
        while(!found && l<r ){
            int mid = (r+l)/2;
            if(nums[mid]<target){
                l = mid+1;
            }else if(nums[mid]>target){
                r = mid;
            }else{
                res = mid;
                found = !found;
            }
            if(l==r && nums[l]==target){
                res = l;
                found = !found;
            }
            cout << l << " " << mid << " " << r << " " << res <<endl;
        }
        return res;
    }
};
