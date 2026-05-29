class Solution {
public:
    int digitSum(int x){
        string s = to_string(x);
        int sum = 0;

        for(char c : s){
            sum += c - '0';
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