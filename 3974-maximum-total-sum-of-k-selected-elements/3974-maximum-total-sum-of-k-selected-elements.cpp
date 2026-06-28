class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i<k; i++){
            if(mul == 0){
                sum += nums[i];
            }else{
                sum +=  1LL * nums[i] * mul;
                mul--;
            }
        }

        return sum;
    }
};