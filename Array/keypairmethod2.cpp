class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j = n-1;

        vector<int>ans;

        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
            sum = 0;
        }
        return ans;
    }
};