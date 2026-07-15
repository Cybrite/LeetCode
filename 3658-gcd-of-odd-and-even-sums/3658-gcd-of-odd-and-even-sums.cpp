class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even = 0;
        int odd = 0;

        even = n*(n+1);
        odd = n*n;

        return gcd(even, odd);
    }
};