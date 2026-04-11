class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int lMax = 0, rMax = 0, ans = 0;

        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= lMax){
                    lMax = height[left];
                }else{
                    ans += lMax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rMax){
                    rMax = height[right];
                }else{
                    ans += rMax - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};