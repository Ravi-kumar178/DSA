class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i <n; i++){
            sum = sum + nums[i];
        }
        //sumofseries
      int  sumAp = n*(n+1)/2;
        int ans = sumAp-sum;
        return ans;
    }
};