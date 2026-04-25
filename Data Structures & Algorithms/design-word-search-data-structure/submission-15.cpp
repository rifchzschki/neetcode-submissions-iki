class WordDictionary {
public:
    unordered_map<char, WordDictionary*> mp;
    bool isLeaf;

    WordDictionary() {
        isLeaf = false;    
    }
    
    void addWord(string word) {
        if(word.empty()) {isLeaf = true; return;}
        char c = word[0];
        if(mp.find(c)==mp.end()){
            mp[c] = new WordDictionary();
        }
        mp[c]->addWord(word.substr(1));
    }
    bool search(string word) {
        if(word.empty()) return isLeaf;
        char c = word[0];
        if(c == '.'){
            for(auto [a,b] : mp){
                if(b->search(word.substr(1))) return true;
            }
            return false;
        }else{
            if(mp.find(c) == mp.end()) return false;
            return mp[c]->search(word.substr(1));
        }
    }
};
