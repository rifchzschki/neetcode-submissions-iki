class MinStack {
private:
    stack<pair<int,int>> ct;

public:
    MinStack() {
    
    }
    
    void push(int val) {
        if(ct.empty()){
            ct.push({val,val});
        }else{
            auto topVal = ct.top();
            ct.push({val, min(topVal.second, val)});
        }
    }
    
    void pop() {
        ct.pop();
    }
    
    int top() {
        auto topVal = ct.top();
        return topVal.first;
    }
    
    int getMin() {
        auto topVal = ct.top();
        return topVal.second;
    }
};
