public:
    
    int countIndex(string& s, char& p, int i , int count){
        //base case
        if(i >= s.size()) return count;
        if(s[i] == p) count = i;
        countIndex(s,p,i+1,count);
    }
    
    int LastIndex(string s, char p){
        //complete the function here
        int i = 0;
        int count = -1;
        int ans = countIndex(s,p,i,count);
        return ans;
    }