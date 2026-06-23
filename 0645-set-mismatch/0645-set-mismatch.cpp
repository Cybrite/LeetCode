class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1);
        int dup = -1, miss = -1;

        for(int x : nums){
            cnt[x]++;
        }

        for(int i=1; i<n+1; i++){
            if(cnt[i] == 2){
                dup = i;
            }else if(cnt[i] == 0){
                miss = i;
            }
        }

        return {dup, miss};
    }
};