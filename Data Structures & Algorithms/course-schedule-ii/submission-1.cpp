class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int node, vector<int>& visited, vector<int>& res){
        if(visited[node]==1) return false;
        if(visited[node]==2) {return true;}

        visited[node]=1;
        for(int neigh: graph[node]){
            if(!dfs(graph, neigh, visited, res)) return false;
        }
        res.push_back(node);
        visited[node]=2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> graph; 
        vector<int> visited(numCourses, 0);

        for(vector<int>& p: prerequisites){
            graph[p[0]].push_back(p[1]);
        }   

        for(int node=0; node<numCourses; node++){
            if(!dfs(graph, node, visited, res)){
                return vector<int>();
            }
        }
        return res;
    }
};
