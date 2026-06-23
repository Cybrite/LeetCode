class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1);
        vector<int> res;

        for(int i=0; i<n; i++){
            cnt[nums[i]]++;
        }

        for(int i=0; i<=n; i++){
            if(cnt[i] == 0){
                res.push_back(i);
            }
        }

        res.erase(res.begin());

        return res;
    }
};