#include <cstring>
class Solution {
public:
    int x[4]={1,-1,0,0}, y[4]={0,0,-1,1};
    int pac[100][100], atl[100][100], vist[100][100];
    int ROWS=0, COLS=0;

    void dfs(int i, int j, vector<vector<int>>& heights, bool isPac){
        vist[i][j] = 1;
        if(isPac){
            pac[i][j]=1;
        }else{
            atl[i][j]=1;
        }
        for(int k=0;k<4;k++){
            int yi = i+y[k], xj = j+x[k];
            if(yi>=0 && yi<ROWS && xj>=0 && xj<COLS && !vist[yi][xj] && heights[yi][xj]>=heights[i][j]){
                dfs(yi, xj, heights, isPac);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS= heights.size(); 
        COLS = heights[0].size();
        memset(pac, 0, sizeof(pac));
        memset(atl, 0, sizeof(atl));
        memset(vist, 0, sizeof(vist));

        for(int j=0;j<COLS;j++){
            dfs(0,j,heights,true);
        }
        for(int i=0;i<ROWS;i++){
            dfs(i,0,heights,true);
        }
        memset(vist, 0, sizeof(vist));
        for(int j=0;j<COLS;j++){
            dfs(ROWS-1,j,heights,false);
        }
        for(int i=0;i<ROWS;i++){
            dfs(i,COLS-1,heights,false);
        }
        
        vector<vector<int>> res;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(pac[i][j]&& atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
