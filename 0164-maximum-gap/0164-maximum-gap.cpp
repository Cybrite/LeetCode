class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        if(n<2) return 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++){
            diff = max(diff, nums[i+1] - nums[i]);
        }

        return diff;
    }
};