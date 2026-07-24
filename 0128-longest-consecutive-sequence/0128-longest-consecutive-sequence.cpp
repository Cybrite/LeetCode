class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uni(nums.begin(), nums.end());
        int cnt = 0;
        
        for(auto& n : uni){
            if(!uni.count(n-1)){
                int curr = n;
                int curr_cnt = 1;

                while(uni.count(curr+1)){
                    curr += 1;
                    curr_cnt += 1;
                }

                cnt = max(cnt, curr_cnt);
            }
        }

        return cnt;
    }
};