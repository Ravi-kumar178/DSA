class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==1) return false;

        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                if(i - mp[nums[i]] <= k){
                    return true;
                }
            }

            //update map value(index)
            mp[nums[i]] = i;
        }
        return false;
    }
};