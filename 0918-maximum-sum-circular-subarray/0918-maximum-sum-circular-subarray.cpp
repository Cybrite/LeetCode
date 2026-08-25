class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum = nums[0], currmax = nums[0];
        int currmin = nums[0], minsum = nums[0];
        int total = nums[0];

        for(int i=1; i<nums.size(); i++){
            total += nums[i];

            currmax = max(nums[i], nums[i]+currmax);
            maxsum = max(maxsum, currmax);

            currmin = min(nums[i], nums[i]+currmin);
            minsum = min(minsum, currmin);
        }
        
        if(maxsum < 0){
            return maxsum;
        }

        return max(maxsum, total - minsum);
    }
};