class Solution {
public:

    int palindrome(string s, int i, int j){
        int count = 0;
        while((i >= 0) && (j < s.size()) && (s[i] == s[j])){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            int oddSum = palindrome(s,i,i);
            int evenSum = palindrome(s,i,i+1);
            sum = sum + oddSum + evenSum;
        }
        return sum;
    }
};