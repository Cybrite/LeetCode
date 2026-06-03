class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;

        for(auto op : operations){
            if(op == "C"){
                st.pop();
            }else if(op == "D"){
                st.push(2*st.top());
            }else if(op == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();

                st.push(x);
                st.push(x+y);
            }else{
                st.push(stoi(op));
            }
        }

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};