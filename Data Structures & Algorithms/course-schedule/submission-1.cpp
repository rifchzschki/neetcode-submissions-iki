class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& grp,vector<int>& visited){
        if(visited[node]==1) return false;
        if(visited[node]==2) return true;

        visited[node]=1;
        for(int& n: grp[node]){
            if(!dfs(n, grp, visited)){
                return false;
            }
        }
        visited[node]=2;
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> grp;
        vector<int> visited(numCourses, 0);

        for(vector<int>& p: prerequisites){
            grp[p[0]].push_back(p[1]);
        }        

        for(int node=0;node<numCourses;node++){
            if(!dfs(node, grp, visited)){
                return false;
            }
        }
        return true;
    }
};
