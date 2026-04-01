class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(nums[left]<=nums[right]){
                left++;
            }else{
                right--;
            }
        }
        return left;
    }
};