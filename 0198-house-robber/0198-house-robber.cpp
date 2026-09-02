class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0;

        for(int i=0; i<nums.size(); i++){
            int curr = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = curr;
        }

        return p1;
    }
};