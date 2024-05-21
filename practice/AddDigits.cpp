class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num > 0){
            int digit = num%10;
            num = num/10;
            sum += digit;
        }

        while(sum > 9){
            num = sum;
            sum = 0;
            while(num > 0){
                int digit = num%10;
                num = num/10;
                sum += digit;
            }
        }
        return sum;
    }
};