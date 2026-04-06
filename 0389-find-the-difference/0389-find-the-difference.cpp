class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0,sum2=0;

        for(char c: s){
            sum1 += (int)c;
        }

        for(char i: t){
            sum2 += (int)i;
        }

        int ans = sum2-sum1;

        return char(ans);
    }
};