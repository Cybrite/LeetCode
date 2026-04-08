class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for(int i=index; i<nums.size(); i++){
            if(seen.count(nums[i])){
                continue;
            }

            seen.insert(nums[i]);

            swap(nums[index], nums[i]);

            backtrack(index+1, nums, res);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        backtrack(0,nums,res);

        return res;
    }
};