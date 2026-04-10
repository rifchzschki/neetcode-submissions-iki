
class Solution {
public:
    int x[4] ={-1,1,0,0};
    int y[4] ={0,0,-1,1};
    
    void dfs(vector<vector<bool>>& visited, vector<vector<char>> grid, int i, int j){
        for(int k;k<4;k++){
            int xi = i+x[k], yj = j+y[k];
            if(xi>=grid.size() || yj>=grid[0].size() || xi<0 || yj<0) continue;
            if(grid[xi][yj]=='1' && !visited[xi][yj]){
                visited[xi][yj] = true;
                dfs(visited, grid, xi, yj);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cout << "visit" << endl;
                    visited[i][j] = true;
                    dfs(visited, grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
