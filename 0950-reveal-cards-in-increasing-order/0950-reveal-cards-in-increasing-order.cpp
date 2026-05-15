class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        vector<int> res(n);

        sort(deck.begin(), deck.end());

        for(int i=0; i<n; i++){
            q.push(i);
        }

        for(int card : deck){
            res[q.front()] = card;
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }
};