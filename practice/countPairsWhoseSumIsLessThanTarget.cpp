class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int count = 0;
        sort(nums.begin(),nums.end());
        while(i < j){
            if(nums[i]+nums[j] < target){
                count += j-i;
                j = nums.size()-1;
                ++i;
            }
            else{
                j--;
            }
        }
        return count;
    }
};