class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        //multisource bfs
        queue<pair<int,int>> q;
        int fresh=0, steps=0, ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));

        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(fresh>0 && !q.empty()){
            int qSize = q.size();
            while(qSize--){
                auto [a,b] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int pa = a+y[k], pb = b+x[k];
                    if(pa>=0 && pa<ROWS && pb>=0 && pb<COLS && !visited[pa][pb] && grid[pa][pb]==1){
                        fresh--;
                        visited[pa][pb] = 1;
                        q.push({pa,pb});
                    }
                }
            }
            steps++;
        }

        return fresh ? -1 : steps;
    }
};
