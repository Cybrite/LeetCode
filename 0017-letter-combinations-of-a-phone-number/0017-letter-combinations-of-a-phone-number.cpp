class Solution {
public:
    vector<string> res;

    void backtrack(string digits, int idx, string curr, unordered_map<char, string>& nums){
        if(idx == digits.size()){
            res.push_back(curr);
            return;
        }

        string letters = nums[digits[idx]];

        for(auto& c : letters){
            backtrack(digits, idx+1, curr+c, nums);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> nums = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        backtrack(digits, 0, "", nums);
        return res;
    }
};