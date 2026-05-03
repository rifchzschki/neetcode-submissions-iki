class Solution {
public:
    vector<int> parent;
    vector<int> sizes;

    int find_set(int a){
        if(parent[a]==a) return a;
        return parent[a] = find_set(parent[a]);
    }

    bool is_connected(int a, int b){
        return find_set(a) == find_set(b);
    }

    int idx(int cols, int x, int y){
        return y*cols+x;
    }

    bool union_set(int a, int b){
        int pa = find_set(a), pb = find_set(b);
        if(pa==pb) return false;
        if(sizes[pa]<sizes[pb]){
            swap(pa, pb);
        }
        parent[pb] = pa;
        sizes[pa]+=sizes[pb];
        return true;
    }

    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();

        parent.resize((ROWS*COLS)+1);   
        sizes.resize((ROWS*COLS)+1,1);

        for(int i=0;i<=COLS*ROWS;i++) parent[i]=i;

        int dirX[2] = {-1, 0};
        int dirY[2] = {0, -1};

        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j]=='X') continue;
                if(i==0 || j==0 || i==ROWS-1 || j==COLS-1) {
                    union_set(idx(COLS, j, i), idx(COLS, COLS, ROWS-1));
                }
                for(int k=0;k<2;k++){
                    int px = j+dirX[k], py = i+dirY[k];
                    if(py >= 0 && py < ROWS && px >= 0 && px < COLS && board[py][px]=='O'){
                        union_set(idx(COLS,j,i), idx(COLS,px,py));
                    }
                }
                
            }
        }   
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
            if(board[i][j] == 'O' && !is_connected(idx(COLS,j,i), idx(COLS, COLS, ROWS-1))) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
