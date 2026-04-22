class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,1,-1};
    const int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        // multisource bfs
        int ROW = grid.size(), COL = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int xi = r+x[k], yj = c+y[k];
                if(xi >= 0 && xi < ROW && yj >=0 && yj <COL && grid[xi][yj]==INF){
                    q.push({xi,yj});
                    grid[xi][yj] = grid[r][c] + 1;
                }
            }
        }

        // vector<vector<int>> res(ROW, vector<int>(COL, 0));
        // for(int i=0;i<ROW;i++){
        //     for(int j=0;j<COL;j++){
        //         if(grid[i][j]==0 || grid[i][j]==-1){
        //             res[i][j] = grid[i][j];
        //         }else{
        //             res[i][j] = distance[i][j];
        //         }
        //     }
        // }
        // grid = res;

    }
};
