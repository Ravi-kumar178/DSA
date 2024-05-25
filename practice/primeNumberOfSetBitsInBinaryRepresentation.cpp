class Solution {
public:

    bool isPrime(int n){
        if(n == 1) return false;
        for(int i = 2; i < n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        while(left <= right){
            int i = left;
            vector<int>arr;
            int count = 0;
            
            while(i > 0){
                int digit = i%2;
                arr.push_back(digit);
                i /= 2;
            }

            for(int i = 0 ; i < arr.size(); i++){
                if(arr[i] == 1) count++;
            }

            for(int i = 0; i < arr.size();i++){
                arr.pop_back();
            }

            if(isPrime(count)) ans++;
            ++left;
        }
        return ans;
    }
};