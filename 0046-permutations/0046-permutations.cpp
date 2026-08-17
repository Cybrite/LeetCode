class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& visited){
        if(nums.size() == curr.size()){
            res.push_back(curr);
        }

        for(int i=0; i<nums.size(); i++){
            if(visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, curr, visited);

            visited[i] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> curr;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, curr, visited);
        return res;
    }
};