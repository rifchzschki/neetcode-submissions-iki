class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for(int col=0;col<9;col++){
            unordered_set<char> rowSet;
            for(int row=0;row<9;row++){
                if(rowSet.count(board[row][col])==1 && board[row][col]!='.'){
                    return false;
                }
                rowSet.insert(board[row][col]);
            }
        }
        // col
        for(int row=0;row<9;row++){
            unordered_set<char> colSet;
            for(int col=0;col<9;col++){
                if(colSet.count(board[row][col])==1 && board[row][col]!='.'){
                    return false;
                }
                colSet.insert(board[row][col]);
            }
        }

        for(int k=0; k<9;k++){
            int rowTmp = (k/3)*3, colTmp = (k%3)*3;
            cout << "rowTmp : " << rowTmp << " colTmp : " << colTmp << " k: " << k <<endl;
            unordered_set<char> segSet;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    char ch = board[rowTmp + r][colTmp + c];
                    if (ch == '.') continue;
                    if (segSet.count(ch)) return false;
                    segSet.insert(ch);
                }
            }
        }
        return true;
    }
};
