class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for(int i=2; i<=n; i++){
            string curr = "";
            int cnt = 1;

            for(int j=1; j<res.length(); j++){
                if(res[j] == res[j-1]){
                    cnt++;
                }else{
                    curr.append(to_string(cnt));
                    curr.push_back(res[j-1]);

                    cnt = 1;
                }
            }

            curr.append(to_string(cnt));
            curr.push_back(res.back());

            res = curr;
        }

        return res;
    }
};