class Solution {
public:

    bool checkPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                //not equal
                bool ans1 = checkPalindrome(s,i+1,j);
                bool ans2 = checkPalindrome(s,i,j-1);
                return ans1 || ans2;
            }
        }
        return true;
    }
};