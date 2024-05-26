class Solution {
public:

    void addStringRE(string& num1, int i, string& num2, int j, string& ans,int carry){
        //base case
        if(i<0 && j<0){
            if(carry)
             ans.push_back(carry+'0');

            return ; 
        }
        //processing
        int sum = 0;
        sum += carry;
        int n1 = i>=0 ? (num1[i]-'0'):0;
        int n2 = j>=0 ?(num2[j]-'0'):0;
        sum += n1;
        sum += n2;
        int digit = sum%10;
        ans.push_back(digit+'0');
        carry = sum/10;

        addStringRE(num1,i-1,num2,j-1,ans,carry);
    }

    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string ans = "";
        int carry = 0;
        addStringRE(num1,i,num2,j,ans,carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};