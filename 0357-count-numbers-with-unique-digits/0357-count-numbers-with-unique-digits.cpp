class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int total = 10;
        int available = 9;
        int uni = 9;

        if(n == 0) return 1;

        while(n>1 && available > 0){
            uni *= available;
            total += uni;
            available--;
            n--;
        }

        return total;
    }
};