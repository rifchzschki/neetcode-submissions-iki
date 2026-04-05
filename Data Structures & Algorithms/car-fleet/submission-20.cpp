class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cont; //position, needed time to target

        for(int i;i<position.size();i++){
            double timeToTarget = (double)(target-position[i])/(double)speed[i];
            cont.push_back({position[i], timeToTarget});
        }

        sort(cont.begin(), cont.end(), [](auto &a, auto &b){return a.first<b.first;});

        // monotonic stack
        stack<double> stTime;
        for(int i;i<cont.size();i++){
            while(!stTime.empty() && cont[i].second >= stTime.top()) stTime.pop();
            stTime.push(cont[i].second);
        }
        return stTime.size();
    }
};
