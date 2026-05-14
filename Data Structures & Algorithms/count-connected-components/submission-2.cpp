class Solution {
public:
    vector<int> parent;
    vector<int> sizes;

    int f_set(int a){
        if(a==parent[a])return a;
        return parent[a] = f_set(parent[a]);
    }

    bool u_set(int a, int b){
        int pa = f_set(a), pb = f_set(b);
        if(pa!=pb){
            if(sizes[pa]<sizes[pb]){
                swap(pa,pb);
            }
            parent[pb] = pa;
            sizes[pa]+=sizes[pb];
            return true;
        }else{
            return false;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sizes.resize(n, 1);

        for(int i=0;i<n;i++) parent[i]=i;
        for(vector<int>& e: edges){
            if(u_set(e[0], e[1])){
                n--;
            }
        }
        return n;
    }
};
