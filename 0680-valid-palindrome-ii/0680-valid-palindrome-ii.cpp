class Solution {
private:
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;

        while(l < r){
            if(s[l] != s[r]){
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }

            l++;
            r--;
        }

        return true;
    }
};