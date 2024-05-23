class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size()-1;i++){ 
            int pushedElem = nums[++i];
            for(int j = 0; j < nums[i-1]; j++){
                ans.push_back(pushedElem);
            }    
        }
        return ans;
    }
};