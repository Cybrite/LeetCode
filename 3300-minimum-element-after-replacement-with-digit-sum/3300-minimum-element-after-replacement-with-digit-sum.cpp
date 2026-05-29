class Solution {
public:
    int digitSum(int x){
        int sum = 0;

        while(x > 0){
            sum += x%10;
            x = x/10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            ans = min(ans, digitSum(nums[i]));
        }

        return ans;
    }
};