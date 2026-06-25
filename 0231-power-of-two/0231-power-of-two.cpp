class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        long long m = 2;

        while(m != n){
            m = 2*m;

            if(m >= n){
                break;
            }
        }

        return m == n;
    }
};