class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int index = 0;
        while(index < n){
            int leftSum = 0;
            int rightSum = 0;
            if(index-1 >= 0){
                for(int i = 0; i < index; i++){
                    leftSum = leftSum + nums[i];
                }
            }
            else{
                leftSum = 0;
            }
            if(index + 1 < n){
                for(int i = index+1; i < n; i++){
                    rightSum = rightSum + nums[i];
                }
            }
            else{
                rightSum = 0;
            }

            if(leftSum == rightSum){
                return index;
            }
            index++;
        }
        return -1;
    }
};