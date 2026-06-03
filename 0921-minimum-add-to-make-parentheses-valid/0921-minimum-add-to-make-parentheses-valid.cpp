class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int sum = 0;

        for(char &ch : s){
            if(ch == '('){
                st.push(ch);
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    sum++;
                }
            }
        }

        return sum + st.size();
    }
};