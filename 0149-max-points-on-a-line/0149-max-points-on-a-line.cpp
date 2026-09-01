class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int globalMax = 0;

        for(int i=0; i<n; i++){
            unordered_map<string,int> slope;
            int localMax = 0;

            for(int j=i+1; j<n; j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int gcd = std::gcd(dx,dy);

                dx /= gcd;
                dy /= gcd;

                if(dx < 0 || (dx == 0 && dy < 0)){
                    dx = -dx;
                    dy = -dy;
                }

                string key = to_string(dy) + "_" + to_string(dx);
                slope[key]++;
                localMax = max(localMax, slope[key]);
            }
            globalMax = max(globalMax, localMax + 1);
        }

        return globalMax;
    }
};