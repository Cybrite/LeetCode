class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> vec;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums1.size();

        for(int i=0; i<n; i++){
            pq.push({nums1[i] + nums2[0] , i, 0});
        }

        while(!pq.empty() && vec.size() < k){
            auto curr = pq.top();
            pq.pop();

            int i = curr[1];
            int j = curr[2];

            vec.push_back({nums1[i], nums2[j]});

            if(j+1 < nums2.size()){
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return vec;
    }
};