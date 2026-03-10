class Solution {
public:

    void generate(vector<string> &ans,int n,string currAns,int openCount,int closeCount){
        if(openCount > n) return;

        if(openCount == n && closeCount == openCount){
            ans.push_back(currAns);
            return;
        }

        generate(ans, n, currAns + "(", openCount + 1, closeCount);

        if(closeCount < openCount) {
            generate(ans, n, currAns + ")", openCount, closeCount + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, n, "", 0, 0);
        return ans;
    }
};