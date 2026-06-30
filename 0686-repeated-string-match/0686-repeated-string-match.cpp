class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string curr = a;
        int cnt = 1;

        while(curr.size() < b.size()){
            curr += a;
            cnt++;
        }

        if(curr.contains(b)){
            return cnt;
        }

        curr += a;

        if(curr.contains(b)){
            return cnt+1;
        }

        return -1;
    }
};