class StockSpanner {
public:
    stack<pair<int, int>> st;
    vector<int> bge; //before greatest element
    int counter=0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        counter++;
        // 100, 80, 60, 70y, 60, 75, 85
        // 100 --> max = 100, if > 100 got 2 else got 1
        // 100, 80 --> max = 100, if > 80 
        // 100, 80, 60
        // 100, 80, 60, 70
        // 100, 80, 60, 70, 60

        // if(st.empty())
        // 100 --> -1
        // 80 --> 100
        // 60 --> 80
        // 70 --> 80
        // 60 --> 70
        // 75 --> 80
        // 85 --> 100
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