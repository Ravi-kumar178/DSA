class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n ;i++){
            int leftSum = 0;
            int rightSum = 0;

            //left sum nikalo
            for(int j = i-1; j>=0; j--){
                leftSum = leftSum + nums[j];
            }

            //right sum nikalo
            for(int k  = i+1; k < n; k++){
                rightSum = rightSum + nums[k];
            }

            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};