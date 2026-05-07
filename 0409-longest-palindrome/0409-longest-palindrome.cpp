class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int l = 0;
        bool found = false;

        for(int i = 0; i<s.length(); i++){
            freq[s[i]] += 1;
        }

        for(const auto& [st , f] : freq){
            if(f%2 == 0){
                l += f;
            }else{
                l += f-1;
                found = true;
            }
        }

        if(found) l += 1;

        return l;
    }
};