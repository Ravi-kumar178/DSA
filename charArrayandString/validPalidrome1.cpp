class Solution {
public:


    bool isPalindrome(string s) {
        int i = 0;
        while(s[i] != '\0'){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i]-'A'+'a';
            }
            i++;
        }
        cout<<"lowercase: "<<s<<endl;
        i = 0;
        while(s[i] != '\0'){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i]>='0' && s[i] <= '9')){
                i++;
            }
            else{
                s.erase(i,1);
                
            }
        }

        cout<<"remove speacial char: "<<s<<endl;
        i = 0;
        int j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};