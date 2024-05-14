class Solution {
public:

    bool search(vector<int>nums , int key){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                return 1;
            }
        }
        return 0;
    }

    int findFinalValue(vector<int>& nums, int original) {
        int key = original;
        for(int i = 0; i < nums.size(); i++){
            bool found = search(nums,key);
            if(found){
                key = key*2;
            }
        }
        return key;
    }
};