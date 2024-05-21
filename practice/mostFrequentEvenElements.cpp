class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(auto num: nums){
            if(num%2 == 0){
                mp[num]++;
            }
        }
        int majority = 0;
        int majorityElement = -1;
        for(const auto &pair:mp){
            if(pair.second > majority){
                majority = pair.second;
                majorityElement = pair.first;
            }
        }
        return majorityElement;
    }
};