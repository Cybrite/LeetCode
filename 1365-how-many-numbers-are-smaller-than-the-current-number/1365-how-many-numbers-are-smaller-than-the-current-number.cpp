class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i] > nums[j]){
                    cnt++;
                }
            }
            res.push_back(cnt);
            cnt = 0;
        }

        return res;
    }
};