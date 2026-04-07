class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, sec = LLONG_MIN, tert = LLONG_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == first || nums[i] == sec || nums[i] == tert) continue;

            // putting 3 sliding
            if(nums[i] > first){
                tert = sec;
                sec = first;
                first = nums[i];
            }else if(nums[i] > sec){
                tert = sec;
                sec = nums[i];
            }else if(nums[i] > tert){
                tert = nums[i];
            }
        }

        if(tert ==  LLONG_MIN){
            return first;
        }else{
            return tert;
        }
    }
};