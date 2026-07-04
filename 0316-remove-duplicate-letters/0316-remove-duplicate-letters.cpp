class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> idk(26,0);
        vector<bool> st(26, false);
        string ans = "";

        for(int i=0; i<s.length(); i++){
            idk[s[i]-'a'] = i;
        }

        for(int i=0; i<s.length(); i++){
            char c = s[i];

            if(st[c - 'a']) continue;

            while(!ans.empty() && c < ans.back() &&  idk[ans.back() - 'a'] > i){
                st[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            st[c-'a'] = true;
        }

        return ans;
    }
};