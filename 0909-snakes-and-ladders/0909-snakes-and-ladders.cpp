class Solution {
public:
    pair<int,int> getCoordinates(int square, int n){
        int zeroIdx = square-1;
        int rowBtm = zeroIdx/n;
        int c;

        int r = n - 1 - rowBtm;

        int offset = zeroIdx % n;
        if(rowBtm % 2 == 0){
            c = offset;
        }else{
            c = n-1-offset;
        }

        return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n*n+1 , -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=1; i<=6; i++){
                int nxtSq = node+i;
                if(nxtSq > n*n) break;
                int destination;

                auto[r,c] = getCoordinates(nxtSq,n);
                if(board[r][c] == -1){
                    destination = nxtSq;
                }else{
                    destination = board[r][c];
                }

                if(dist[destination] == -1){
                    dist[destination] = dist[node] + 1;
                    q.push(destination);
                }

                if(destination == n*n){
                    return dist[destination];
                }
            }
        }

        return -1;
    }
};