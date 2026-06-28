class Solution {
public:
    long long solve(vector<int>& nums, int k, bool multiply) {
        const long long NEG = -(1LL << 60);

        long long noOp = nums[0];
        long long val = multiply ? 1LL * nums[0] * k : nums[0] / k;
        long long inOp = val;
        long long doneOp = NEG;

        long long ans = max(noOp, inOp);

        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long y = multiply ? x * k : x / k;

            long long newNoOp = max(x, noOp + x);

            long long newInOp = max({
                y,
                noOp + y,
                inOp + y
            });

            long long newDoneOp = max(
                inOp + x,
                doneOp + x
            );

            noOp = newNoOp;
            inOp = newInOp;
            doneOp = newDoneOp;

            ans = max({ans, noOp, inOp, doneOp});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums, k, true), solve(nums, k, false));
    }
};