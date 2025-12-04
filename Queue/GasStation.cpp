class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, balance = 0, deficit = 0;

        for(int i = 0; i < gas.size(); i++){
            int temp = gas[i]-cost[i] + balance;
            if(temp >= 0){
                balance = temp;
            }
            else{
                deficit += abs(temp);
                balance = 0;
                start = i+1;
            }
        }

        if(balance-deficit >= 0) return start;

        return -1;
    }
};