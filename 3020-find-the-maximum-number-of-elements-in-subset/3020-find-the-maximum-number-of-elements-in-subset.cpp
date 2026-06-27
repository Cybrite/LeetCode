class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        int ans = 1;

        for(auto n : nums){
            freq[n]++;
        }

        if(freq.count(1)){
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);
        }

        for(auto [key, val] : freq){
            if(key == 1){
                continue;
            }

            long long curr = key;
            int l = 0;

            while(true){
                if(!freq.count(curr)){
                    break;
                }

                if(freq[curr] == 1){
                    l += 1;
                    break;
                }

                long long next = curr*curr;

                if(!freq.count(next)){
                    l += 1;
                    break;
                }

                l += 2;
                curr = next;
            }

            ans = max(l, ans);
        }

        return ans;
    }
};