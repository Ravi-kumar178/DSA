class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = 0;

        while(i < nums.size()-1){
           int j = i+1;
           while(j < nums.size()){
             int diff = nums[j] - nums[i];
             if(diff == k){
                count++;  
             }
             else if(diff>k){
                break;
             } 
             j++;
           }
          i++; 
        }
        return count;
    }
};