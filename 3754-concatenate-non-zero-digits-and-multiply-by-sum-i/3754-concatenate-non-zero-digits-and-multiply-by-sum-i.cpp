class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string m = to_string(n);
        erase(m, '0');

        long long sum = 0;
        long long x = stoll(m);

        for(auto& s : m){
            sum += s - '0';
        }

        return x*sum;
    }
};