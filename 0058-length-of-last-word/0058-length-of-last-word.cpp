class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length  = 0;
        int i = n-1;

        // skipping the spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        // counting the letters
        while(i >= 0 && s[i] != ' '){
            length++;
            i--;
        }

        return length;
    }
};