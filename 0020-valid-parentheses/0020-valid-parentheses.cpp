class Solution {
public:
    bool isValid(string s) {
       stack<char> ch;

       for(char i:s){
        if(i=='(' || i=='{' || i=='['){

            ch.push(i);

        }else if(i==')' || i=='}' || i==']'){

            if(ch.empty()){
                return false;
            }

            char topCh = ch.top();
            ch.pop();

            if((i == ')' && topCh != '(') || (i == '}' && topCh != '{') | (i == ']' && topCh != '[')){
                return false;
            }
        }
       }

       return ch.empty();
    }
};