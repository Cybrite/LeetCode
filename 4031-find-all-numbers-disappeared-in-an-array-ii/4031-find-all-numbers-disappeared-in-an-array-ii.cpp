class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        long long prev = (long long)lower - 1;

        for(long long num : nums){
            if(num<lower || num>upper){
                continue;
            }

            if(num - prev >= 2){
                ans.push_back({(int)(prev+1), (int)(num-1)});
            }

            prev = num;
        }

        if((long long)upper - prev >= 1){
            ans.push_back({(int)(prev+1), upper});
        }

        return ans;
    }
};