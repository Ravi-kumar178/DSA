class Solution {
public:

    int solve(vector<int>& nums, int size, int index){
        if(index >= size) return 0;
        int option1 = nums[index]+solve(nums,size,index+2);
        int option2 = 0 + solve(nums,size,index+1);
        return max(option1,option2);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums,size,index);
        return ans;
    }
};