class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Compute distance of every cell from nearest thief
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Binary Search
        int low = 0;
        int high = 2 * n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canReach(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool canReach(vector<vector<int>>& dist, int safe) {
        int n = dist.size();

        if(dist[0][0] < safe)
            return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0] = true;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return true;

            for(auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   !vis[nx][ny] &&
                   dist[nx][ny] >= safe) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};