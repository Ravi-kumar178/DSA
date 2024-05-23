class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>ans;
        for(int num: nums){
            if(num >= k){
                ans.push_back(num);
            }
        }

        return nums.size()-ans.size();
    }
};