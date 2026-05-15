class Solution {
public:
    vector<int> parent;
    vector<int> sizes;

    int f_set(int a){
        if(parent[a]==a)return a;
        return parent[a] = f_set(parent[a]);
    }

    bool u_set(int a, int b){
        int pa = f_set(a), pb = f_set(b);
        if(pa==pb) return false;
        if(sizes[pa]<sizes[pb]){
            swap(pa,pb);
        }
        parent[pb] = pa;
        sizes[pa] += sizes[pb];
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n);
        sizes.resize(n, 1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<int> res={-1,-1};
        for(vector<int>& e: edges){
            if(!u_set(e[0]-1,e[1]-1)) res=e;
        }
        return res;
    }
};
