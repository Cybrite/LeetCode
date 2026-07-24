class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt = 0;
        int ele = 0;

        for(auto& n : nums){
            mp[n]++;
        }

        for(auto& [n,f] : mp){
            if(cnt < f){
                cnt = f;
                ele = n;
            }
        }

        return ele;
    }
};