class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxi = nums[0];
        int mini = nums[0];

        for(int i = 1 ; i<nums.size(); i++){
            int n = nums[i];

            if(n<0){
                swap(maxi, mini);
            }
               
            maxi = max(n, maxi*n);
            mini = min(n, mini*n);
            ans = max(ans, maxi); 
        }

        return ans;
    }
};