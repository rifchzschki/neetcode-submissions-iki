class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;

        int i=0, j=0;
        while(j<k){
            pq.push({nums[j], j});
            j++;
        }
        res.push_back(pq.top().first);

        while(j<nums.size()){
            while(!pq.empty() && pq.top().second <= i) pq.pop();
            pq.push({nums[j], j});
            res.push_back(pq.top().first);
            j++;
            i++;
        }
        return res;
    }
};
