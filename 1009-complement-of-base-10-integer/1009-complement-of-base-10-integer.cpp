class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int fin = 1;
        while(fin <= n){
            fin <<= 1;
        }

        return (fin-1)^n;
    }
};