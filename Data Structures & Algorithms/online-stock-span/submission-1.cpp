class StockSpanner {
public:
    stack<pair<int, int>> st;
    int counter=0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        counter++;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans;
        if(st.empty()){
            ans = counter;
        }else{
            ans = counter - st.top().second;
        }
        st.push({price, counter});
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */