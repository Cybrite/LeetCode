class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            vector<int> digits;

            while(temp>0){
                digits.push_back(temp%10);
                temp = temp/10;
            }

            reverse(digits.begin(), digits.end());

            for(auto d : digits){
                res.push_back(d);
            }
        }

        return res;
    }
};