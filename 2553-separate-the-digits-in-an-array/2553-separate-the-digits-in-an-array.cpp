class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for(auto it : nums){
            string sub = to_string(it);

            for(auto s : sub){
                res.push_back(s-'0');
            }
        }

        return res;
    }
};