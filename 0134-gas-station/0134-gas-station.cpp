class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x = accumulate(gas.begin(), gas.end(), 0);
        int y = accumulate(cost.begin(), cost.end(), 0);
        int current_tank = 0;
        int start_station = 0;

        if(y > x) return -1;

        for(int i = 0; i<gas.size(); i++){
            current_tank += gas[i] - cost[i];
            
            if(current_tank < 0){
                start_station = i+1;
                current_tank = 0;
            }
        }

        return start_station;
    }
};