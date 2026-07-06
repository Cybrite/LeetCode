class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a , const vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int valid = 0;
        int max_end = -1;

        for(int i=0; i<intervals.size(); i++){
            int end = intervals[i][1];

            if(end > max_end){
                valid++;
                max_end = end;
            }
        }

        return valid;
    }
};