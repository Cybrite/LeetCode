class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int idx){
        if(idx == word.size()) return true;

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[idx]){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '*';

        bool found = backtrack(board, word, r-1, c, idx+1) || backtrack(board, word, r+1, c, idx+1) ||
        backtrack(board, word, r, c-1, idx+1) || backtrack(board, word, r, c+1, idx+1);

        board[r][c] = temp;

        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(backtrack(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};