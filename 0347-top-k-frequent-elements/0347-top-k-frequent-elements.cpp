class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<pair<int,int>> arr;
        vector<int> res;

        for(auto num : nums){
            freq[num]++;
        }

        for(auto p : freq){
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        for(int i=0; i<k; i++){
            res.push_back(arr[i].second);
        }

        return res;
    }
};