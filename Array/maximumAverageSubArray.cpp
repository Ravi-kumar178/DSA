class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k-1;
        
        int sum = 0;
        for(int y = i; y <= j; y++){
            sum = sum + nums[y];
        }
        int maxSum = sum;
        j++;
        while(j < nums.size()){
            sum = sum - nums[i];
            i++;
            sum = sum + nums[j];
            j++;
            maxSum = max(sum,maxSum);
        }

        double avg  = maxSum/(double)k;
        return avg;
    }
};