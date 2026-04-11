class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), box(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char val = board[i][j];
                if(val == '.') continue;

                int boxIndex= (i/3)*3 + (j/3);
                if(rows[i].count(val) || cols[j].count(val) || box[boxIndex].count(val)){
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                box[boxIndex].insert(val);
            }
        }

        return true;
    }
};