class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> preGcd(n);
        int curr = 0;
        long long sum = 0;
        int left = 0;
        int right = n-1;

        for(int i=0; i<n; i++){
            curr = max(curr, nums[i]);
            preGcd[i] = gcd(nums[i], curr);
        }

        sort(preGcd.begin(), preGcd.end());

        while(left < right){
            sum += gcd(preGcd[left], preGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};