class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, mx=0;
        for(int r=1;r<prices.size();r++){
            if(prices[l]>=prices[r] && r!=prices.size()-1) l = r;
            else{
                mx = max(mx, prices[r]-prices[l]);
            }
            cout << l << " " << r << endl;
        }
        if(mx<0) return 0;
        else return mx;
    }
};
