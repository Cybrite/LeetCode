class Solution {
public:
    vector<vector<string>> res;
    vector<bool> cols;
    vector<bool> posDia;
    vector<bool> negDia;

    void backtrack(int row, int n, vector<string>& board){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            int pDia = row + col;
            int nDia = row - col + n - 1;

            if(cols[col] || posDia[pDia] || negDia[nDia]) continue;

            cols[col] = posDia[pDia] = negDia[nDia] = true;
            board[row][col] = 'Q';

            backtrack(row+1, n, board);

            cols[col] = posDia[pDia] = negDia[nDia] = false;
            board[row][col] = '.';
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        cols.assign(n, false);
        posDia.assign(2*n-1, false);
        negDia.assign(2*n-1, false);

        backtrack(0, n, board);
        return res;
    }
};