class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int& cnt){
        for(int k=0; k<4; k++){
            int xi = i+x[k], yj = j+y[k];
            if(xi>=0 && xi<grid.size() && yj>=0 && yj<grid[0].size() && grid[xi][yj]==1 && !visited[xi][yj]){
                visited[xi][yj] = 1;
                cout << "DEBUG " << xi << " " << yj << " " << cnt << endl;
                dfs(grid, visited, xi,yj, cnt);
                cnt++;
            }
            
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCnt=0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int cnt = 0;
                    dfs(grid, visited, i, j, cnt);
                    cout << "DEBUG root " << i << " " << j << " " << cnt << endl;
                    if(!cnt) cnt++;
                    maxCnt = max(maxCnt, cnt);
                }
            }
        }
        return maxCnt;    
    }
};
