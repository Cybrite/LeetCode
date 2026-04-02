class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char> substr;
       int left = 0;
       int maxLength = 0;

       for(int i=0; i<s.size(); i++){
         while(substr.find(s[i]) != substr.end()){
            substr.erase(s[left]);
            left++;
         }
         substr.insert(s[i]);
 
         maxLength = max(maxLength, i-left+1);
       } 
       return maxLength;
    }
};