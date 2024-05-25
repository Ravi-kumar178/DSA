class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int sum = 0 , carry = 0;
        string ans;
        while(i >= 0 || j >= 0 ||carry){
            sum = carry;
            if(i >= 0) sum += a[i]-'0';
            if(j >= 0) sum += b[j]-'0';
            carry = sum/2;
            ans.push_back(sum%2+'0');
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};