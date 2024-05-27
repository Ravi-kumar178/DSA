class Solution {
public:

    int minCost(vector<int>& days, vector<int>& costs,int i){
        if(i >= days.size()) return 0;

        int cost1 = costs[0] + minCost(days,costs,i+1);
        //7 day pass
        int passEndDays = days[i]+7-1;
        int j = i;
        while(j<days.size() && days[j] <= passEndDays){
            j++;
        }
        int cost7 = costs[1] + minCost(days,costs,j);

        //30 days pass
        passEndDays = days[i]+30-1;
         j = i;
        while(j<days.size() && days[j] <= passEndDays){
            j++;
        }
        int cost30 = costs[2] + minCost(days,costs,j);

        return min(cost1,min(cost7,cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i = 0;
        return minCost(days,costs,i);
    }
};