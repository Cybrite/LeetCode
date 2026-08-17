class Solution {
public:
    int minOperations(string s) {
       int n = s.size();
        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            int op = i;
            for(int j=0; j<n/2; j++){
                int a = s[(j+i)%n] - 'a';
                int b = s[(n-1-j+i)%n] - 'a';

                int diff = abs(a-b);
                op += min(diff, 26-diff);
            }

            ans = min(ans, op);
        }

        return ans;
    }
};