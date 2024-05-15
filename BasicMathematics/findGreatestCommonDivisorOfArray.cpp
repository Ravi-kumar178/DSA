class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int A = nums[0];
        int B = nums[nums.size()-1];

        while(A > 0 && B > 0){
            if(A>B){
                A = A-B;
            }
            else{
                B = B-A;
            }
        }
        return A==0?B:A;
    }
};