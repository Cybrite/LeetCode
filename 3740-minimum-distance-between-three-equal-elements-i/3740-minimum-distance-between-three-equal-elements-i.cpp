class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            indices_map[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        
        for (const auto& pair : indices_map) {
            const vector<int>& indices = pair.second;
            
            if (indices.size() >= 3) {
                for (int h = 0; h < indices.size() - 2; ++h) {
                    int i = indices[h];          
                    int k = indices[h + 2];   
                    
                    int dist = 2 * (k - i);
                    min_dist = min(min_dist, dist);
                }
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};