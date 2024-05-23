class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        for(int num: nums){
            ans.push_back(num);
        }
        for(int num:nums){
            ans.push_back(num);
        }
        return ans;
    }
};