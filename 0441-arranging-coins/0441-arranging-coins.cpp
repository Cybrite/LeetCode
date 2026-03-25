class Solution {
public:
    int arrangeCoins(int n) {
        int r = n;
        if(r == 1) return 1;
        for(int i = 1; i<=n; i++){
            if(r >= i){
                r -= i;
            }else{
                return i-1;
            }
        }
        return r;
    }
};