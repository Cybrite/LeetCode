class Solution {
public:
    vector<string> result;
    
    void backtrack(string digits, int index, string current, 
                   unordered_map<char, string>& phone) {
        
        if(index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index]];

        for(char c : letters) {
            backtrack(digits, index + 1, current + c, phone);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> phone = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };

        backtrack(digits, 0, "", phone);
        return result;
    }
};