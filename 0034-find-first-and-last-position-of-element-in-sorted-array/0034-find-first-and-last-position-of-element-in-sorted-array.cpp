class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = lowerBound(nums, target + 1) - 1;
        if(first == nums.size() || nums[first] != target) return {-1,-1};
        return {first,last};
    }
};