class Solution {
public:
    string clearDigits(string s) {
        string res = "";

        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                if(!res.empty()){
                    res.pop_back();
                }
            }else{
                res.push_back(s[i]);
            }
        }

        return res;
    }
};