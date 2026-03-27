class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int l=0; l<n/2; l++){
            int first = l;
            int last = n-1-l;

            for(int i=first; i<last; i++){
                int offset = i - first;
                int temp = matrix[first][i];

                matrix[first][i] = matrix[last-offset][first]; // left->top
                matrix[last-offset][first] = matrix[last][last-offset]; //bottom->left
                matrix[last][last-offset] = matrix[i][last]; //right->bottom
                matrix[i][last] = temp; // top->bottom
            }
        }
    }
};