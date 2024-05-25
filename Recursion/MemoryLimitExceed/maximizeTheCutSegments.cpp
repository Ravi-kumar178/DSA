 int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        if(n==0) return 0;
        if(n < 0) return INT_MIN;
        
        int option1 = maximizeTheCuts(n-x,x,y,z)+1;
        int option2 = maximizeTheCuts(n-y,x,y,z)+1;
        int option3 = maximizeTheCuts(n-z,x,y,z)+1;
        int ans = max(option2,option3);
        int finalAns = max(option1,ans);
        return finalAns;
    }