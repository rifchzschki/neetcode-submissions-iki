class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int res = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[r] < nums[mid]){
                l = mid+1;
            }else{
                r = mid;
            }
            res = min(res, min(nums[l], nums[r]));
            if(r-l<2)break;
            cout << l << " " << r << " " << mid  << " " << res << endl;
        }
        return res;
    }
};
