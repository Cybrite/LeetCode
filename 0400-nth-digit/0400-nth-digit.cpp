class Solution {
public:
    int findNthDigit(int n) {

        long digit = 1;     // number of digits (1-digit, 2-digit...)
        long count = 9;     // how many numbers in this block
        long start = 1;     // starting number of the block

        // Step 1: find the correct block
        while(n > digit * count){
            n -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }

        // Step 2: find the actual number
        long number = start + (n - 1) / digit;

        // Step 3: find the digit inside the number
        int index = (n - 1) % digit;

        string s = to_string(number);
        return s[index] - '0';
    }
};