class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        unordered_map<int,int> ranks;
        int curr_rank = 1;

        sort(sorted.begin(), sorted.end());

        for(int n : sorted){
            if(ranks.find(n) == ranks.end()){
                ranks[n] = curr_rank;
                curr_rank++;
            }
        }

        for(int i=0; i<arr.size(); i++){
            arr[i] = ranks[arr[i]];
        }

        return arr;
    }
};