class Solution {
public:

    void bestTime(vector<int>& prices, int& maxProfit, int& minPrice, int index){

        //bc
        if(index >= prices.size()) return;

        if(prices[index] < minPrice){
            minPrice = prices[index];
        }
        else{
            maxProfit = max(maxProfit,prices[index]-minPrice);
        }
        bestTime(prices,maxProfit,minPrice,index+1);
    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        int index = 1;
        bestTime(prices,maxProfit,minPrice,index);
        return maxProfit;
    }
};