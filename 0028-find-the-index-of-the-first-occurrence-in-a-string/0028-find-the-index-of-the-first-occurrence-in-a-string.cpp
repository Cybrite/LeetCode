class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m == 1){
            for(int i=0; i<n; i++){
                if(haystack[i] == needle[0]){
                    return i;
                }
            }
            return -1;
        }else{
         for(int i=0; i<=n-m; i++){
            int j = 0;
            while(j<m && haystack[i+j] == needle[j] ){
                j++;
            }
            if(j == m){
                return i;
            }
         }

         return -1;
        }

        return 0;
    }
};