class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;

        int i=0, j=0;
        while(j<nums.size()){
            pq.push({nums[j], j});
            if(j>=k){
                while(!pq.empty() && pq.top().second <= i) pq.pop();
                res.push_back(pq.top().first);
                i++;
            }
            j++;
            if(j==k) res.push_back(pq.top().first);
        }
        return res;
    }
};
