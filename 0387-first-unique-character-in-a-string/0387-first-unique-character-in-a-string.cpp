class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> st;

        for(char c:s){
            st[c]++;
        }

        for(int i=0; i<s.length(); i++){
            if(st[s[i]]== 1){
                return i;
            }
        }

        return -1;
    }
};