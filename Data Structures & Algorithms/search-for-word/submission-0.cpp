class Solution {
public:
    string curr;
    vector<int> x={0,0,-1,1};
    vector<int> y={1,-1,0,0};
    vector<vector<int>> visited;

    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if(idx >= word.size()) {return true;};
        bool isFound = false;
        for(int k=0;k<4;k++){
            int pi = i+x[k], pj = j+y[k];
            if(pi>=0 && pi<board.size() && pj>=0 && pj<board[0].size() && !visited[pi][pj] && board[pi][pj]==word[idx]){
                visited[pi][pj] = 1;
                isFound |= backtrack(board, word, pi, pj, idx+1);
                visited[pi][pj] = 0;
            }
        
        } 
        return isFound;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool isFound = false;
        visited = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    isFound |= backtrack(board,word, i, j, 1);
                    visited[i][j]=0;
                }
            }
        }
        return isFound;
    }
};
