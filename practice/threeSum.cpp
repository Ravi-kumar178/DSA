class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2;i++){
           
            if((i-1 >= 0)&&(nums[i] == nums[i-1])){
                continue;
            }
            else{
                
                int j = i+1;
                int k = nums.size()-1;
                while(j < k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    }
                    else if(sum > 0){
                        k--;
                    }
                    else if(sum < 0){
                        j++;
                    }
                  /*   if((j<k)&&(k+1 < nums.size())&&(nums[k] == nums[k+1])){
                        k--;
                    }
                    if((j<k)&&nums[j] == nums[j+1]){
                        j++;
                    } */
                    
                }
            }
        }
        return ans;
    }
};