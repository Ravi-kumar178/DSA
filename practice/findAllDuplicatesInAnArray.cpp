class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0, index = 0;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        
        if(nums.size() == 1){
            return ans;
        }
        else{
           int j = 1;
           while(j < nums.size()){
             if(nums[i] == nums[j]){
                ans.push_back(nums[i]);
             }
             j++;
             i++;
           }
          
        }
        return ans;
    }
};