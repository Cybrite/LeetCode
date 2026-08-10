class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> order;
        queue<int> q;

        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            inDegree[a]++;
        }

        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for(int j : adj[curr]){
                inDegree[j]--;
                if(inDegree[j] == 0){
                    q.push(j);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>{};
    }
};