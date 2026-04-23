class KthLargest {
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int val: nums){
            add(val);
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if(pq_.size()>k_){
                pq_.pop();
        }
        return pq_.top();
    }
};
