class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closetSum = nums[1] + nums[2] + nums[3];

        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int currentSum = nums[i] + nums[j] + nums[k];

                if(abs(currentSum - target) < abs(closetSum - target)){
                    closetSum = currentSum;
                }
                if(currentSum == target){
                    return currentSum;
                }
                if(currentSum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }

        return closetSum;
    }
};