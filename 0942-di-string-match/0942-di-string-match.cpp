class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> res;
        int j = 0, d = n;

        for(int i=0; i<n; i++){
            if(s[i] == 'I'){
                res.push_back(j++);
            }
            else{
                res.push_back(d--);
            }
        }
        res.push_back(j);

        return res;
    }
};