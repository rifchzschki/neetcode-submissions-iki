class Solution {
public:
    vector<int> parent;
    vector<int> sizes;

    int find_set(int a){
        if(parent[a]==a) return a;
        return parent[a]=find_set(parent[a]);
    }

    bool union_set(int a, int b){
        int pa = find_set(a), pb = find_set(b);
        if(pa==pb)return false;
        if(sizes[pa]<sizes[pb]){
            swap(pa,pb);
        }
        parent[pb]=pa;
        sizes[pa]+=sizes[pb];
        return true;
    }

    bool is_connected(int a, int b) {return find_set(a)==find_set(b);}

    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sizes.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(vector<int> ed: edges){
            if(!union_set(ed[0],ed[1])) return false;
        }
        for(int i=1;i<edges.size();i++){
            if(!is_connected(edges[i][0],edges[i-1][0])) return false;
        }
        return true;
    }
};
