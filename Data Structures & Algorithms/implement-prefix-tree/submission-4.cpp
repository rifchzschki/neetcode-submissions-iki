class PrefixTree {
public:
    PrefixTree* child[26];
    bool isLeaf;

    PrefixTree() {
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isLeaf = false;
    }
    
    void insert(string word) {
        if(word.empty()) return;
        char s = word[0];
        if(!child[s-'a']){
            child[s-'a'] = new PrefixTree();
        }
        if(word.size()==1) {
            isLeaf = true;
        }
        child[s-'a']->insert(word.substr(1));
        cout << "insert: " << word <<" "<< isLeaf << endl;
    }
    
    bool search(string word) {
        char s = word[0];
        if(!child[s-'a']){
            return false;
        }
        cout << word << " " << isLeaf << endl;
        if(word.size()>1){
            return child[s-'a']->search(word.substr(1, word.size()-1));
        }else{
            return isLeaf;
        }
    }
    
    bool startsWith(string prefix) {
        char s = prefix[0];
        if(!child[s-'a']){
            return false;
        }
        if(prefix.size()>1){
            return child[s-'a']->startsWith(prefix.substr(1, prefix.size()-1));
        }else{
            return true;
        }
        
    }
};
