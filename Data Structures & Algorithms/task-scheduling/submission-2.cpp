class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for(char task: tasks){
            mp[task]++;
        }
        
        priority_queue<int> pq;
        for(auto [a,b]: mp){
            if(!a) continue;
            pq.push(b);
        }
        queue<pair<int, int>> q;

        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                auto b = pq.top();pq.pop();
                b--;
                if(b>0) q.push({time+n, b});
            }
            if(!q.empty() && q.front().first == time){
                pq.push(q.front().second);
                q.pop();
            }
        };

        return time;
    }
};
