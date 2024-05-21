class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }

        int majority = 0;
        for(const auto& pair: mp){
            if(pair.second > nums.size()/4){
                majority = pair.first;
            }
        }
        return majority;
    }
};