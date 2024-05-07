class Solution 
{
    public:
    
    bool possibleSolution(int A[],int N,int M,int mid){
        int pageSum = 0;
        int count = 1;
        
        for(int i = 0; i < N; i++){
            if(A[i] > mid){
                return false;
            }
            if(pageSum + A[i] > mid){
                count++;
                pageSum = A[i];
                if(count > M){
                    return false;
                }
            }
            else{
                pageSum = pageSum + A[i];
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N){
            return -1;
        }
        
        int s = 0;
        int e = accumulate(A,A+N,0);
        int mid = s+(e-s)/2;
        int ans = -1;
        
        while(s <= e){
            if(possibleSolution(A,N,M,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};