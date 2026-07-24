class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romans = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;

        for(int i=0; i<s.length(); i++){
            if(i < s.length()-1 && romans[s[i]] < romans[s[i+1]]){
                res -= romans[s[i]];
            }else{
                res += romans[s[i]];
            }
        }

        return res;
    }
};