class Solution {
public:
    vector<int> parent;
    vector<int> sizes;

    int f_set(int a){
        if(a==parent[a])return a;
        return parent[a] = f_set(parent[a]);
    }

    void u_set(int a, int b){
        int pa = f_set(a), pb = f_set(b);
        if(pa!=pb){
            if(sizes[pa]<sizes[pb]){
                swap(pa,pb);
            }
            parent[pb] = pa;
            sizes[pa]+=sizes[pb];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sizes.resize(n, 1);

        for(int i=0;i<n;i++) parent[i]=i;
        unordered_set<int> s;
        for(vector<int>& e: edges){
            u_set(e[0], e[1]);
            
        }
        for(int i=0;i<n;i++) s.insert(f_set(i));
        return s.size();
    }
};
