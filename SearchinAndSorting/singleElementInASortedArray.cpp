class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s <= e){
            if(s==e){
                return nums[s];
            }
            else if(mid&1){
                //left part
                if((mid-1 >= 0) && nums[mid] == nums[mid-1]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            else{
                //leftpart
                if((mid+1 < n) && nums[mid] == nums[mid+1]){
                    s = mid+2;
                }
                else{
                    e = mid;
                }
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
};