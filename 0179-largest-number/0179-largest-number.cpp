class Solution {
public:
    static bool cmp(string &a, string &b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        string ans = "";

        for(int i=0; i<nums.size(); i++){
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(), arr.end(), cmp);

        if(arr[0] == "0") return "0";

        for(string s : arr){
            ans += s;
        }

        return ans;
    }
};