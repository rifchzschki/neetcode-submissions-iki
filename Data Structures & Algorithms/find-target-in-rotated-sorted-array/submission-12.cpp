class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            // if right sorted -> right>target>mid; we go to the right
            //                 -> else; go to the left
            // if left sorted -> left<target<mid; we go to the left
            //                 -> else; go to the right
            // if target == mid -> you have found the solution
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            cout << nums[l] << " " << nums[r] << " " << nums[mid] << endl;
            if(nums[r] > nums[mid]){
                if(nums[r]>=target && target>=nums[mid]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }else{
                if(nums[l]<=target && target<=nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};

// 3 4 5 1 2
