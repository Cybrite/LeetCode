class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        vector<vector<int>> res;
        vector<vector<int>> ans;

        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<int> curr = occupiedIntervals[0];

        for(int i = 1; i<n; i++){
            if (occupiedIntervals[i][0] <= curr[1] + 1){
                curr[1] = max(curr[1], occupiedIntervals[i][1]);
            }else{
                res.push_back(curr);
                curr = occupiedIntervals[i];
            }
        }
        res.push_back(curr);

        for(auto &n : res){
            int l = n[0];
            int r = n[1];

            if(r < freeStart || l > freeEnd){
                ans.push_back(n);
            }else if(freeStart <= l && freeEnd >= r){
                continue;
            }else if(l < freeStart && freeEnd >= r){
                ans.push_back({l, freeStart-1});
            }else if(freeStart <= l && r > freeEnd){
                ans.push_back({freeEnd+1, r});
            }else if(l < freeStart && r > freeEnd){
                ans.push_back({l , freeStart-1});
                ans.push_back({freeEnd+1, r});
            }
        }

        return ans;
    }
};