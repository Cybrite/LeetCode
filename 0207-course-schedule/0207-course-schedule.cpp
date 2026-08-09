class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        int courseTaken = 0;

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
            courseTaken++;

            for(int j : adj[curr]){
                inDegree[j]--;

                if(inDegree[j] == 0){
                    q.push(j);
                }
            }
        }

        return courseTaken == numCourses;

    }
};