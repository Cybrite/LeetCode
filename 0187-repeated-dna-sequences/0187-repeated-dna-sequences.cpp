class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;

        if (s.length() < 10) return {};

        for (int i = 0; i <= s.length() - 10; i++) {
            string sub = s.substr(i, 10);

            if (seen.count(sub)) {
                res.insert(sub);
            } else {
                seen.insert(sub);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};