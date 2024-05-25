class Solution {
public:

    int countSetBits(vector<int> &arr){
        int count = 0;
        for(int num : arr){
            if(num == 1) count++;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int>ans;
        int i = 0;
        while(i <= n){
            int a = i;
            int count = 0;
            vector<int>arr;
            while(a > 0){
                int digit = a%2;
                arr.push_back(digit);
                a /= 2;
            }
            count = countSetBits(arr);
            for(int i = 0; i < arr.size(); i++){
                arr.pop_back();
            }
            ans.push_back(count);
            ++i;
        }
        return ans;
    }
};