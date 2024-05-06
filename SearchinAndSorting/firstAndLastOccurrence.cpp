  public:
    
    int firstOcc(int arr[],int n, int x){
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        
        while(start <=  end){
            if(arr[mid] == x){
                ans = mid;
                end = mid-1;
            }
            else if (x > arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
    
    int lastOcc(int arr[],int n, int x){
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        
        while(start <= end){
            if(x == arr[mid]){
                ans = mid;
                start = mid+1;
            }
            else if(x > arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>ans;
        int res1 = firstOcc(arr,n,x);
        ans.push_back(res1);
        int res2 = lastOcc(arr,n,x);
        ans.push_back(res2);
        return ans;
    }