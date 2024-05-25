class Solution {
public:
    int hammingWeight(int n) {
        vector<int>arr;
        int ans = 0;
        while(n > 0){
            int digit = n%2;
            arr.push_back(digit);
            n /= 2;
        }
        for(int num: arr){
            if(num == 1) ans++;
        }
        return ans;
    }
};