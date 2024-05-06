public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int start = 0;
        int end = n-1;
        int mid = (start) + (end-start)/2;
        
        while(start <= end){
            if(arr[mid] == k){
                return mid;
            }
            else if(k > arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }