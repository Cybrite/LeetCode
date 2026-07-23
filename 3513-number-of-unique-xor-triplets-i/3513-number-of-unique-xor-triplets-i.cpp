class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        int pw_2 = 1;

        while(pw_2 <= n){
            pw_2 *= 2;
        }

        return pw_2;
    }
};