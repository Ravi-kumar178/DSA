class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;

        for(auto num: nums){
            mp[num]++;
        }

        int majority = 0;
        for(const auto& pair: mp){
            if(pair.second > nums.size()/2){
                majority = pair.first;
                break;
            }
        }
        return majority;
    }
};