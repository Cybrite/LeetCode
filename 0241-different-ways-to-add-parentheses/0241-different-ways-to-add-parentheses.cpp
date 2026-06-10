class Solution {
public:
    vector<int> solve(string expr){
        vector<int> ans;

        for(int i=0; i<expr.size(); i++){
            char c = expr[i];

            if(c == '-' || c == '+' || c == '*'){
                string left = expr.substr(0,i);
                string right = expr.substr(i+1);

                vector<int> L = solve(left);         
                vector<int> R = solve(right);

                for(int a : L){
                    for(int b : R){
                        if(c == '+'){
                            ans.push_back(a+b);
                        }else if(c == '-'){
                            ans.push_back(a-b);
                        }else{
                            ans.push_back(a*b);
                        }
                    }
                }         
            }
        }

        if(ans.empty()){
            ans.push_back(stoi(expr));
        }

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        // REMEMBER
        // split then use recursion to find all possiblilities
        return solve(expression);
    }
};