class Solution {
public:
    int getHoursEat(vector<int>& piles, int k){
        int res=0;
        
        cout << "Count ceil: "<<endl;
        for(int val: piles){
            res += ceil((double)val/k);
            cout << res << endl;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int res = 1000000000;
        while(l<=r){
            int mid = l + (r-l)/2;
            int val = getHoursEat(piles, mid);
            cout << l << " " << r << " " << mid << " " << val << " " << res << endl;
            if(val == h) {res = min(res,mid);}
            if(val>h){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(res==1000000000)return l;
        return res;
    }
};
