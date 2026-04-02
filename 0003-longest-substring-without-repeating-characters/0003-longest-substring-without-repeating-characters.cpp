class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char, int> m;
       int left = 0;
       int maxLength = 0;

       for(int i=0; i<s.size(); i++){
        if(m.find(s[i]) != m.end()){
            left = max(left, m.at(s[i]) + 1);
        }
        m[s[i]] = i;
        maxLength = max(maxLength, i-left+1);
       }
       
       return maxLength;
    }
};