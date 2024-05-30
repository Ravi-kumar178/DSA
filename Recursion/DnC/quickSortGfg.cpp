  public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        //base case
        if(low >= high) return;
        int pivot = high;
        int i = low-1;
        int j = low;
        while(j < pivot){
            if(arr[j] < arr[pivot]){
                ++i;
                swap(arr[j],arr[i]);
            }
            ++j;
        }
        ++i;
        swap(arr[i],arr[pivot]);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
    }