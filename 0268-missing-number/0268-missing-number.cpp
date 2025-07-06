class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum_of_nums = 0;
        int sum_of_n = ((nums.size()+1)*(nums.size()))/2;

        for(auto it : nums){
            sum_of_nums += it;
        }

        return sum_of_n - sum_of_nums;
    }
};