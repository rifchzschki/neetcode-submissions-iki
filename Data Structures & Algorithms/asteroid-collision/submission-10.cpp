class Solution {
public:
    bool isColl(int a, int b){
        if(a>0 && b<0) return true; 
        else return false;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> dq;
        dq.push_back(asteroids[0]);
        for(int i = 1;i<asteroids.size();i++){
            int ast = asteroids[i];
            if(dq.empty() || !isColl(dq.back(), ast)){
                dq.push_back(ast);
            }else{
                int isAdd = true;
                while(!dq.empty() && isColl(dq.back(), ast) && abs(dq.back())<=abs(ast)){
                    int backVal = dq.back();
                    dq.pop_back();
                    if(abs(backVal)==abs(ast)){
                        isAdd = false;
                        break;
                    }
                }
                if(isAdd && (dq.empty() || !isColl(dq.back(), ast))){
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


