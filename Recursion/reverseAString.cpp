class Solution
{
    public:
    
    void reverseString(string& s, int i , int j){
        //base case
        if(i>j) return;
        //processing
        swap(s[i],s[j]);
        reverseString(s,i+1,j-1);
    }
    
    string reverseWord(string str)
    {
        // Your code goes here
        int i = 0;
        int j = str.size()-1;
        reverseString(str,i,j);
        return str;
    }
};