class Solution {
public:
    int bs(vector<int>&nums,int s, int target){
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        while(s <= e){
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n; i++){
            if(bs(nums,i+1,nums[i]+k) != -1){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }
};