class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ctos;
        unordered_map<string, char> stoc;
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word){
          words.push_back(word);
        }

        if(pattern.length() != words.size()) return false;

        for(int i=0; i<pattern.size(); i++){
            char c = pattern[i];
            string w = words[i];

            if(ctos.count(c)){
                if(ctos[c] != w){
                    return false;
                }
            }

            if(stoc.count(w)){
                if(stoc[w] != c){
                    return false;
                }
            }

            ctos[c] = w;
            stoc[w] = c;
        }

        return true;
    }
};