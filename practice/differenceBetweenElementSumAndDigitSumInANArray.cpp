class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = 0;
        int digitSum = 0;

        for(int num: nums){
            elemSum += num;
        }

        for(int i = 0; i < nums.size(); i++){
            int number = nums[i];
            while(number > 0){
                int digit = number%10;
                digitSum += digit;
                number /= 10;
            }
        }

        return abs(digitSum - elemSum);
    }
};