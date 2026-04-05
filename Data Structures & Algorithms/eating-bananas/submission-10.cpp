class Solution {
public:
    int getHoursEat(vector<int>& piles, int k){
        int res=0;
        
        for(int val: piles){
            res += ceil((double)val/k);
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int res = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            int val = getHoursEat(piles, mid);
            if(val == h) {res = min(res,mid);}
            if(val>h){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(res==INT_MAX)return l;
        return res;
    }
};
