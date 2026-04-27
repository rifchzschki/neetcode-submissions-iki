class Solution {
public:
    int partition(vector<int>& arr, int l, int r){
        int pivot = arr[l];
        int i=l-1, j=r+1;
        while(true){
            do{
                i++;
            }while(arr[i]<pivot);
            
            do{
                j--;
            }while(arr[j]>pivot);

            if(i>=j){
                return j;
            }
            swap(arr[i], arr[j]);
        }
    }

    int quickSelect(vector<int>& arr, int l, int r, int k){
        int pi = partition(arr, l, r);
        if(l == r) return arr[l];

        if(pi>=k){
            return quickSelect(arr, l, pi, k);
        }else{
            return quickSelect(arr, pi+1, r, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
};
