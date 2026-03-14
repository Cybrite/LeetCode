class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        long long fact = 1;

        for(int i = 1; i <= n; i++){
            nums.push_back(i);
            fact *= i;
        }

        fact /= n;
        k--;

        string ans = "";

        while(nums.size() > 1){

            int index = k / fact;
            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            k %= fact;
            fact /= nums.size();
        }

        ans += to_string(nums[0]);

        return ans;
    }
};
