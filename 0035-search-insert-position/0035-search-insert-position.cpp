class Solution {
public:

    int findMe(vector<int> &nums, int &target, int start, int end){
        if(start > end) return start;

        int middle = (start + end) / 2;

        if(nums[middle] == target){
            return middle;
        }

        if(nums[middle] > target){
            return findMe(nums, target, start, middle - 1);
        }

        return findMe(nums, target, middle + 1, end);
    }

    int searchInsert(vector<int>& nums, int target) {
        return findMe(nums, target, 0, nums.size() - 1);
    }
};