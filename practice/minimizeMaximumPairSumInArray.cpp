class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int result = INT_MIN;
        while(i < j){
          int sum = nums[i]+nums[j];
          result = max(result,sum);
          i++;
          j--;
        }
        return result;
    }
};