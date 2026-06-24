class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int x = 0;
        
        for(int i = 1; i <= n && x < target.size(); i++){
            res.push_back("Push");

            if(i == target[x]){
                x++;
            }else{
                res.push_back("Pop");
            }
        }

        return res;
    }
};