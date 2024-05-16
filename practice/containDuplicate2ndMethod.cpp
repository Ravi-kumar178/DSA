class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       if(nums.size() == 1) return false;
    
       map<int,int>mp;

       for(int i = 0; i < nums.size();i++){
         if(mp.find(nums[i]) != mp.end()){
            return true;
         }
         mp[nums[i]] = i;
       }
       return false;
    }
};