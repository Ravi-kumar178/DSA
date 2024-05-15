class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, count = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == prev){
                count++;
            }
            else{
                if(count >= 2){
                    nums[k++] = prev;
                    nums[k++] = prev;
                    prev = nums[i];
                    count = 1;
                }
                else{
                    nums[k++] = prev;
                    prev = nums[i];
                }
            }
        }

        if(count >= 2){
            nums[k++] = prev;
            nums[k++] = prev;
        }
        else{
            nums[k++] = prev;
        }
        return k;
    }
};