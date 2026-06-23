class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v1(nums.begin(), nums.begin()+n);
        vector<int> v2(nums.begin()+n, nums.end());
        vector<int> res;

        for(int i=0; i<n; i++){
            res.push_back(v1[i]);
            res.push_back(v2[i]);
        }

        return res;
    }
};