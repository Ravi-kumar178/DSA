 int peakElement(int arr[], int n)
    {
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;
        
       
       int s = 0;
       int e = n-1;
       int mid = s + (e-s)/2;
       
       while(s < e){
           if(arr[mid+1] >= arr[mid]){
               s = mid+1;
           }
           else{
               e = mid;
           }
           mid = s+(e-s)/2;
       }
      return s;
    }