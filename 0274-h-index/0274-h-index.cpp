class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;

        sort(citations.rbegin(), citations.rend());

        for(int i=0; i<citations.size(); i++){
            int curr = i+1;

            if(citations[i] >= curr){
                h = curr;
            }else{
                break;
            }
        }

        return h;
    }
};