class Solution {
public:
    int maxNumberOfBalloons(string text) {
       int cnts[26] = {0};

       for(char c : text){
        cnts[c - 'a']++;
       }

       int b = cnts['b' - 'a'];
       int a = cnts['a' - 'a'];
       int l = cnts['l' - 'a'] / 2;
       int o = cnts['o' - 'a'] / 2;
       int n = cnts['n' - 'a'];

       return min({b,a,l,o,n});
    }
};