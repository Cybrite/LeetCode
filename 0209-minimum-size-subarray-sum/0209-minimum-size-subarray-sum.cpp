class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int res = INT_MAX;

        for(int i = 1; i <= n; i++){
            int needed = prefix[i] - target;

            auto it = upper_bound(prefix.begin(), prefix.end(), needed);

            if(it != prefix.begin()){
                it--;
                int j = it - prefix.begin();
                res = min(res, i - j);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};