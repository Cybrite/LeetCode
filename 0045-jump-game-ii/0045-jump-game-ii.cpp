class Solution {
public:
    int jump(vector<int>& nums) {
        int far = 0;
        int jump_end = 0;
        int jumps = 0;
        int n = nums.size();

        for(int i = 0; i<n-1; i++){
            if(far < i){
                return 0;
            }

            far = max(far , nums[i] + i);

            if(i == jump_end){
                jumps++;
                jump_end = far;
            }
        }
        
        return jumps;
    }
};