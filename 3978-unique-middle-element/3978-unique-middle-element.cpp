class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        unordered_map<int, int> freq;

        for(auto& i : nums){
            freq[i]++;
        }

        return freq[nums[mid]] > 1 ? false : true;
    }
};