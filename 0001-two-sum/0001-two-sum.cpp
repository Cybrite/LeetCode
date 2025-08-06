class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int k;
        int f;



        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(i != j && nums[i] + nums[j] == target){
                    k = i;
                    f = j;
                    break;
                }
            }
        }
        res.push_back(k);
        res.push_back(f);

        return res;
    }
};