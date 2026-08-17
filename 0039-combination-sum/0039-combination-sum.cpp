class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int start, int target, vector<int>& candidates, vector<int>& curr){
        if(target<0){
            return;
        }else if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            backtrack(i, target-candidates[i], candidates, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0, target, candidates, curr);
        return res;
    }
};