class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;

        for(int x : nums){
            mp[x]++;
        }

        for(auto p : mp){
            if(p.second >= 2){
                res.push_back(p.first);
            }
        }

        return res;
    }
};