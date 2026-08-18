class Solution {
public:
    int total = 0;
    vector<bool> cols;
    vector<bool> posdia;
    vector<bool> negdia;

    void backtrack(int row, int n){
        if(row == n){
            total++;
            return;
        }

        for(int col = 0; col<n; col++){
            int pdia = row + col;
            int ndia = row - col + n - 1;

            if(cols[col] || posdia[pdia] || negdia[ndia]) continue;

            cols[col] = posdia[pdia] = negdia[ndia] = true;

            backtrack(row+1, n);

            cols[col] = posdia[pdia] = negdia[ndia] = false;
        }
    }

    int totalNQueens(int n) {
        cols.assign(n, false);
        posdia.assign(2*n - 1, false);
        negdia.assign(2*n - 1, false);

        backtrack(0, n);

        return total;
    }
};