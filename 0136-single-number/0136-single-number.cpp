class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int n : nums){
            freq[n]++;
        }

        for(auto [num,cnt] : freq){
            if(cnt == 1){
                return num;
                break;
            }
        }

        return 0;
    }
};