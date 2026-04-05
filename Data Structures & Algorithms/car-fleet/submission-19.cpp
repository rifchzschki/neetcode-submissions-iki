class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cont; //position, needed time to target

        for(int i;i<position.size();i++){
            double timeToTarget = (double)(target-position[i])/(double)speed[i];
            // cout <<  ceil(4.0/3.0) << endl;
            // cout <<  (target-position[i]) << endl;
            // cout <<  (speed[i]) << endl;
            // cout <<  ceil((target-position[i])/speed[i]) << endl;
            // cout << timeToTarget << endl;
            cont.push_back({position[i], timeToTarget});
        }

        sort(cont.begin(), cont.end(), [](auto &a, auto &b){return a.first<b.first;});

        // monotonic stack
        stack<double> stTime;
        for(int i;i<cont.size();i++){
            cout << cont[i].first<< ">>" << cont[i].second <<endl;
            while(!stTime.empty() && cont[i].second >= stTime.top()) stTime.pop();
            stTime.push(cont[i].second);
        }
        return stTime.size();
    }
};
