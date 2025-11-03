class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> seen;
        vector<int> arr;

        for(int ele : nums1){
            seen.insert(ele);
        }

        for(auto i : nums2){
            if(seen.count(i)){
                arr.push_back(i);
                seen.erase(i);
            }
        }

        return arr;
    }
};