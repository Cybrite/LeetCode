class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        for(auto it = nums.begin() ; it != nums.end()-1; it++){
            auto mini = it;
            for(auto j = it; j != nums.end(); j++){
                if(*j < *mini){
                    mini = j;
                }
            }
            int temp = *mini;
            *mini = *it;
            *it = temp;
        }

        if(nums.size() < 2){
            return 0;
        }else{
            int mino = INT_MAX;
        for(int i = 0; i <= nums.size() - k; i++) {
            int nMin = nums[i + k - 1] - nums[i];
            mino = min(mino, nMin);
        }

        return mino;
        }
    }
};