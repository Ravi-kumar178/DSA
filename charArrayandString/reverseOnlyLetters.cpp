class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i <= j){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
                if((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};