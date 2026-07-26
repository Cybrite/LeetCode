class Solution {
private:
    int getVal(vector<vector<int>>& series, int t){
        auto it = lower_bound(series.begin(), series.end(), t, [](const vector<int>& a, int val){
            return a[0] < val;
        });

        if(it != series.end()){
            return (*it)[1];
        }

        return 0;
    }
    
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<int> timestamps;
        vector<vector<int>> ans;
        
        for(auto& i : series1){
            timestamps.insert(i[0]);
        }
        for(auto& i : series2){
            timestamps.insert(i[0]);
        }

        for(int t : timestamps){
            int val1 = getVal(series1, t);
            int val2 = getVal(series2, t);

            ans.push_back({t, val2+val1});
        }

        return ans;
    }
};