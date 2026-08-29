class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> vec;
        priority_queue<int> pq;
        int ptr = 0;
        int n = profits.size();

        for(int i=0; i<n; i++){
            vec.push_back({capital[i], profits[i]});
        }

        sort(vec.begin(), vec.end());

        for(int i=0; i<k; i++){
            while(ptr < n && vec[ptr][0] <= w){
                pq.push(vec[ptr][1]);
                ptr++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};