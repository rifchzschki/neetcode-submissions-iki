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
        // int it = 0;
        // while(k-- && it<nums.size()){
        //     pq_.push(nums[it]);
        //     it++;
        // }
        // while(it<nums.size()){
        //     add(nums[it]);
        //     it++;
        // }
    }
    
    int add(int val) {
        pq_.push(val);
        if(pq_.size()>k_){
                pq_.pop();
        }
        return pq_.top();
    }
};
