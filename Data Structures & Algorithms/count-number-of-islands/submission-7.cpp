
class Solution { // dsu solution
public:
    int x[4] ={-1,1,0,0};
    int y[4] ={0,0,-1,1};

    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v){
        if(parent[v]==v)return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_set(int a, int b){
        int pa = find_set(a);
        int pb = find_set(b);
        if(pa==pb) return false; // same
        else{
            if(size[pa]<size[pb]) swap(a,b);
            parent[pb] = pa;
            size[pa]+=size[pb];
            return true;
        }
    }

    // int idx(int i, int j, int col){
    //     return i*col+j;
    // }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), res_cnt=0;
        auto idx = [&](int i, int j){
            return i*col+j;
        };
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    // make_set 
                    make_set(idx(i,j));
                    res_cnt++;
                    for(int k=0;k<4;k++){
                        int xi = i+x[k], yj = j+y[k];
                        if(xi>=0 && xi<row && yj>=0 && yj<col){
                            // find --> apakah udah ada, kalau belum cont
                            if(parent.count(idx(xi,yj)) && union_set(idx(i,j), idx(xi,yj))){
                                res_cnt--;
                            }
                        }
                    }
                }
            }
        }
        return res_cnt;
    }
};
