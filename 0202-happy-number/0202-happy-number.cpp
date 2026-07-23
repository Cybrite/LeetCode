class Solution {
private:
   int getNext(int n){
    int total_sum = 0;

    while(n > 0){
        int x = n%10;
        total_sum += x*x;
        n = n/10;
    }

    return total_sum;
   }

public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1 && !seen.count(n)){
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};