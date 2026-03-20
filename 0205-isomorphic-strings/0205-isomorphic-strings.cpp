class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();

        vector<bool> marked(256,false);
        vector<int> map(256,-1);

        for(int i=0; i<n; i++){
            unsigned char c1 = s[i] - 'a';
            unsigned char c2 = t[i] - 'a';

            if(map[c1] == -1){
                if(marked[c2]) return false;

                map[c1] = c2;
                marked[c2] = true;
            }else if(map[c1] != c2){
                return false;
            }
        }
        return true;
    }
};