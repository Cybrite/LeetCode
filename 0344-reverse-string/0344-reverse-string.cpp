class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> r(s);
        int n = r.size() - 1;

        for(int i = 0; i<s.size(); i++){
            s[i] = r[n];
            n--;
        }
    }
};