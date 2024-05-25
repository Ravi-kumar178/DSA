class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;

        int sum = 0, carry = 0;
        string ans;
        while(i >= 0 || j >= 0 || carry){
            sum = carry;
            if(i >= 0) sum += num1[i]-'0';
            if(j >= 0) sum += num2[j]-'0';
            carry = sum/10;
            ans.push_back(sum%10 + '0');
            i--;
            j--;        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};