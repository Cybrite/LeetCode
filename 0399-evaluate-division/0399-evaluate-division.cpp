class Solution {
public:
    double dfs(string curr, string target, unordered_set<string>& visited, unordered_map<string, unordered_map<string, double>>& graph) {
        if(visited.contains(curr)) return -1;

        visited.insert(curr);

        if(curr == target) return 1.0;

        for (auto neighbor : graph[curr]) {
            string nextCity = neighbor.first;
            double ticketPrice = neighbor.second;
            double result = dfs(nextCity, target, visited, graph);

            if (result != -1.0) {
                return ticketPrice * result; 
            }
        }

        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> res;

        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];

            double weights = values[i];

            graph[u][v] = values[i];
            graph[v][u] = 1.0/values[i];
        }

        for(int i=0; i<queries.size(); i++){
            string start = queries[i][0];
            string end = queries[i][1];

            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                res.push_back(-1);
            }else{
                unordered_set<string> visited;

                double ans = dfs(start,end,visited,graph);
                res.push_back(ans);
            }
        }

        return res;
    }
};