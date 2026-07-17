class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for(int x : nums){
            max_val = max(max_val, x);
        }

        vector<int> ans;
        vector<long long> count(max_val+1, 0);
        vector<long long> gcd_pairs(max_val+1, 0);
        vector<long long> prefix(max_val+1, 0);

        for(int x : nums){
            count[x]++;
        }

        for(int i = max_val; i>=1; i--){
            long long multiples_count = 0;
            long long total_pairs = 0;

            for(int j=i; j<=max_val; j+=i){
                multiples_count += count[j];
            }

            total_pairs = multiples_count * (multiples_count-1)/2;

            for(int j=2*i; j<=max_val; j+=i){
                total_pairs = total_pairs - gcd_pairs[j];
            }

            gcd_pairs[i] = total_pairs;
        }

        for(int i=1; i<=max_val; i++){
            prefix[i] = prefix[i-1] + gcd_pairs[i];
        }

        for(auto& q : queries){
            auto ub = upper_bound(prefix.begin(), prefix.end(), q);
            int idx = ub - prefix.begin();
            ans.push_back(idx);
        }

        return ans;
    }
};