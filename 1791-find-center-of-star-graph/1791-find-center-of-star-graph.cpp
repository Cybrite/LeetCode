class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+2);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<adj.size(); i++){
            if(adj[i].empty()) continue;

            if(adj[i].size() > 1){
                return i;
            }
        }

        return -1;
    }
};