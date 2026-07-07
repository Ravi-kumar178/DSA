class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int y = n;
        while(y > 0){
            int digit = pow(10,(int)log10(y));
            int num = 0;
            if(digit == 0){
                x = x*10 + y;
                break;
            }

            num = y/digit;
            if(num != 0) x = x*10+num;
            
            y = y%digit;
            cout<<y<<endl;
        }
        int num = x;
        long long sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }

        return (long long)x * sum;
    }
};