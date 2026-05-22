class Solution {
public:
    bool isEdge(const string& word1, const string& word2){
        if(word1.size() != word2.size()) return false;

        int cnt = 0;
        for(int i = 0; i < word1.size(); i++){
            if(word1[i] != word2[i]) cnt++;
            if(cnt > 1) return false;
        }

        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        bool hasEnd = false;
        for(string& word : wordList){
            if(word == endWord) hasEnd = true;
        }

        if(!hasEnd) return 0;

        wordList.push_back(beginWord);
        int startIdx = n;
        n++;

        vector<vector<int>> graph(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isEdge(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(startIdx);
        visited[startIdx] = true;

        int step = 1; 

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int currIdx = q.front();
                q.pop();

                if(wordList[currIdx] == endWord){
                    return step;
                }

                for(int neigh : graph[currIdx]){
                    if(!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }

            step++;
        }

        return 0;
    }
};