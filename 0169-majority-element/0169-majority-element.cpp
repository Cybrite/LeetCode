class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
         
        for(int num : nums) {
            count[num]++;
        }
        
        int majorityElem = nums[0];
        int maxCount = 0;
        
        for(auto& [num, freq] : count) {
            if(freq > maxCount) {
                maxCount = freq;
                majorityElem = num;
            }
        }
        
        return majorityElem;
    }
};