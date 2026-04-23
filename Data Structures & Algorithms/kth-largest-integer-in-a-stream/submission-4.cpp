class KthLargest {
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        int it = 0;
        while(k-- && it<nums.size()){
            pq_.push(nums[it]);
            it++;
        }
        while(it<nums.size()){
            add(nums[it]);
            it++;
        }
    }
    
    int add(int val) {
        if(pq_.size()<k_){
            pq_.push(val);
        }else{
            if(val>pq_.top()){
                pq_.pop();
                pq_.push(val);
            }
        }
        return pq_.top();
    }
};
