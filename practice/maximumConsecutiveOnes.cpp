class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int maxCount = 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                ++count;
            }
            else{
                maxCount = max(count,maxCount);
                count = 0;
            }
            ++i;
        }
        maxCount = max(count,maxCount);
        return maxCount;
    }
};