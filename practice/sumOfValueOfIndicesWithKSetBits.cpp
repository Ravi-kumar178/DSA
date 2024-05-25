class Solution {
public:
    int countSetBits(vector<int>&arr){
        int count = 0;
        for(int num : arr){
            if(num == 1){
                count++;
            }
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int i = 0;
        vector<int>brr;
        while(i < nums.size()){
            int a = i;
            int count = 0;
            vector<int>arr;
            if(a == 0){
                arr.push_back(0);
            }
            else{
                while(a > 0){
                int digit = a%2;
                arr.push_back(digit);
                a /= 2;
               }
            }
            count = countSetBits(arr);
            brr.push_back(count);
            for(int j = 0; j < arr.size(); j++){
                arr.pop_back();
            }
            i++;
        }
        int sum = 0;
        for(int i = 0; i < brr.size(); i++){
            if(brr[i] == k) sum += nums[i];
        }
        return sum;
    }
};