class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int originalNum = x;
        x = abs(x);
        while(x > 0){
            int digit = x%10;
            ans = ans*10+digit;
            x /= 10;
        }

        if(originalNum < 0){
            ans *= -1;
        }
        cout<<ans<<endl;
        if(ans < INT_MIN || ans > INT_MAX){
            return 0;
        }
        return ans;
    }
};