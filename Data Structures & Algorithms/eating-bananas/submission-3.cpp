class Solution {
public:
    long long getHoursEat(vector<int>& piles, long long k){
        long long res=0;
        
        cout << "Count ceil: "<<endl;
        for(int val: piles){
            res += ceil((double)val/k);
            cout << res << endl;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1;
        long long r=*max_element(piles.begin(), piles.end());
        long long res = 1000000000;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long val = getHoursEat(piles, mid);
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
