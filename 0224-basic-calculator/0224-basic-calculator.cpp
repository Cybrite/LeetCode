class Solution {
public:
    int calculate(string s) {
        stack<long long> cps;
        long long res = 0;
        long long sign = 1;
        long long num = 0;

        for(char c : s){
            if(isdigit(c)){
                num = (num*10) + (c - '0');
            }else if(c == '+' || c == '-'){
                res += sign*num;

                num = 0;
                sign = c == '+' ? 1 : -1;
            }else if(c == '('){
                cps.push(res);
                cps.push(sign);

                res = 0;
                sign = 1;
            }else if(c == ')'){
                res += sign*num;
                num = 0;

                res = res * cps.top();
                cps.pop();

                res += cps.top();
                cps.pop();
            }
        }

        res += (sign*num);

        return (int)res;
    }
};