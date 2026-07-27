class Solution {
public:
    bool isColl(pair<int, int> a, pair<int, int> b){
        if(a.first<b.first && a.second>0 && b.second<0) return true; 
        else if(a.first>b.first && a.second<0 && b.second>0) return true; 
        else return false;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;
        dq.push_back(asteroids[0]);
        for(int i = 1;i<asteroids.size();i++){
            int ast = asteroids[i];
            if(dq.empty() || !isColl({i-1, dq.back()}, {i, ast})){
                dq.push_back(ast);
            }else{
                int isAdd = true;
                while(!dq.empty() && isColl({i-1, dq.back()}, {i, ast}) && abs(dq.back())<=abs(ast)){
                    int backVal = dq.back();
                    dq.pop_back();
                    if(abs(backVal)==abs(ast)){
                        isAdd = false;
                        break;
                    }
                }
                if(isAdd && (dq.empty() || !isColl({i-1, dq.back()}, {i, ast}))){
                    dq.push_back(ast);
                }

            }
        }
        if(dq.size()){
            return vector<int>(dq.begin(), dq.end());
        }else{
            return vector<int>();
        }
    }
};


