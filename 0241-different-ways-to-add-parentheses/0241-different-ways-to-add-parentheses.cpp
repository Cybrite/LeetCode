class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> solve(string expr) {

        if(memo.count(expr))
            return memo[expr];

        vector<int> ans;

        for(int i = 0; i < expr.size(); i++) {

            char c = expr[i];

            if(c == '+' || c == '-' || c == '*') {

                string left = expr.substr(0, i);
                string right = expr.substr(i + 1);

                vector<int> L = solve(left);
                vector<int> R = solve(right);

                for(int a : L) {
                    for(int b : R) {

                        if(c == '+')
                            ans.push_back(a + b);

                        else if(c == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        if(ans.empty()) {
            ans.push_back(stoi(expr));
        }

        return memo[expr] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};