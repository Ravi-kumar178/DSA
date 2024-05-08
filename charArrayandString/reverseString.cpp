class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        cout<<j<<endl;

        while(i <= j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};