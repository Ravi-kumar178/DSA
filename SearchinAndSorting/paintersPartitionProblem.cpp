class Solution
{
  public:
  
    bool isPossibleSolution(int arr[],int n, int k, long long int mid){
        int count = 1;
       long long int totalSum = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > mid){
                return false;
            }
            if(totalSum + arr[i] > mid){
                count++;
                totalSum = arr[i];
                if(count > k){
                    return false;
                }
            }
            else{
                totalSum = totalSum + arr[i];
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
      
      long long  int ans = -1;
      long long  int s = 0;
      long long  int e =0;
      for(int i = 0; i < n; i++){
          e = e+arr[i];
      }
       long long int mid = s+(e-s)/2;
        
        while(s <= e){
            if(isPossibleSolution(arr,n,k,mid)){
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