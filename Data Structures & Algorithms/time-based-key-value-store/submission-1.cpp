class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> umap;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        if(umap.find(key)!=umap.end()){
            umap[key].push_back({timestamp, value});
        }else{
            vector<pair<int, string>> newv;
            newv.push_back({timestamp, value});
            umap[key] = newv;
        }
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key)!=umap.end()){
            vector<pair<int, string>> values = umap[key];
            auto it = upper_bound(values.begin(), values.end(), timestamp, [](int a, pair<int, string> &b){
                return a < b.first;
            });
            return it == values.begin() ? "" : prev(it)->second;
        }
        return "";
    }
};
