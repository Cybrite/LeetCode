class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt = 0;

        for(int i=0; i<arr1.size(); i++){
            int target = arr1[i];
            auto it = lower_bound(arr2.begin(),arr2.end(),target);

            bool isValid = true;

            if(it != arr2.end() && abs(*it - target) <= d){
                isValid = false;
            }
            if(it != arr2.begin() && abs(*(it-1)-target) <= d){
                isValid = false;
            }

            if(isValid){
                cnt++;
            }
        }

        return cnt;
    }
};