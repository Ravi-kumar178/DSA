class Solution{
public:	
	
	bool checkPalindrome(string& s, int i , int j){
	    //base case
	    if(i>j) return true;
	    if(s[i] != s[j]) return false;
	    
	    checkPalindrome(s,i+1,j-1);
	}
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int i = 0;
	    int j = S.size()-1;
	    bool ans = checkPalindrome(S,i,j);
	    return ans;
	}
