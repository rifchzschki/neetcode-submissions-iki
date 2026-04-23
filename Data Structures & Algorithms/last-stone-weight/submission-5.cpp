class Solution {
public:
    priority_queue<int> pq;

    int lastStoneWeight(vector<int>& stones) {
        pq = priority_queue<int>(stones.begin(), stones.end());

        while(pq.size()>1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            cout << x << " " << y << " " << pq.size() <<endl;
            if(x != y){
                pq.push(abs(x-y));
            }
        }
        if(!pq.empty()) return pq.top();
        else return 0;
    }
};
