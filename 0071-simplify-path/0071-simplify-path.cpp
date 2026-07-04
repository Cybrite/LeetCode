class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;
        string res = "";

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }else if(token == ".."){
                if(st.empty()){
                    continue;
                }else{
                    st.pop_back();
                }
            }else{
                st.push_back(token);
            }
        }

        if(st.empty()) return "/";

        for(int i=0; i<st.size(); i++){
            res += "/" + st[i];
        }

        return res;
    }
};