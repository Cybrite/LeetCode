class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<int> st;
        int prevTime = 0;

        for(auto& s : logs){
            int id = stoi(s.substr(0, s.find(':')));
            int time = stoi(s.substr(s.rfind(':')+1));

            if(s.find('e') != string::npos){
                res[id] += time - prevTime + 1;
                st.pop();
                prevTime = time+1;
            }else{
                if(!st.empty()){
                    res[st.top()] += (time-prevTime);
                }
                st.push(id);
                prevTime = time;
            }
        }

        return res;
    }
};