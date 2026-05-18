class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int x : nums1){
            int idx = -1;
            int greater = -1;

            for(int i=0; i<nums2.size(); i++){
                if(nums2[i] == x){
                    idx = i;
                    break;
                }
            }

            for(int i = idx+1; i<nums2.size(); i++){
                if(nums2[i] > x){
                    greater = nums2[i];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};