class Solution {
public:

    string palindrome(string s, int i , int j){
        string ans;
        while((i >= 0)&&(j < s.size())&&(s[i] == s[j])){
            i--;
            j++;
        }
        for(int a = i+1; a < j; a++){
            ans.push_back(s[a]);
        }
        return ans;
    }

    string longestPalindrome(string s) {
        string str = " ";
        for(int i = 0; i < s.size();i++){
            string ans1 = palindrome(s,i,i);
            string ans2 = palindrome(s,i,i+1);

            if(ans1.size() >= str.size() && ans1.size() > ans2.size()){
                str = ans1;
            }
            else if(ans2.size() >= str.size() && ans2.size() > ans1.size()){
                str = ans2;
            }
        }
        return str;
    }
};