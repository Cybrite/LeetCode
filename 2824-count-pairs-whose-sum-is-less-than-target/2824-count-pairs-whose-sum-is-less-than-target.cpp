class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1, cnt = 0;

        while(left < right){
            int sum = nums[left] + nums[right];

            if(sum < target){
                cnt += (right-left);
                left++;
            }else{
                right--;
            }
        }

        return cnt;
    }
};