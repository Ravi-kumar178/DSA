class Solution {
public:
    long long minCost(vector<int>& ropes) {
        priority_queue<int,vector<int>,greater<int>>hp;
        
        for(int i = 0; i < ropes.size(); i++){
            hp.push(ropes[i]);
        }
        
        long long totalSum = 0;
        while(hp.size() > 1){
            int firstEle = hp.top(); hp.pop();
            int secondEle = hp.top(); hp.pop();
            
            int sum = firstEle + secondEle;
            totalSum += sum;
            
            hp.push(sum);
        }
        return totalSum;
    }
};