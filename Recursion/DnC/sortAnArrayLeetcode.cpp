class Solution {
public:

    void mergeArray(vector<int>& nums, int s, int e){
        int mid = s+(e-s)/2;
        vector<int>leftArray;
        vector<int>rightArray;
        int leftArrayLength = mid-s+1;
        int rightArrayLength = e-mid;
        int realArrayIndex = s;
        //copying the left array
        for(int i = 0; i < leftArrayLength; i++){
            leftArray.push_back(nums[realArrayIndex++]);
        }
       // realArrayIndex = mid+1;
        for(int i = 0; i < rightArrayLength; i++){
            rightArray.push_back(nums[realArrayIndex++]);
        }

        //two pointer method
        int i = 0;
        int j = 0;
        realArrayIndex = s;
        while((i < leftArrayLength)&&(j < rightArrayLength)){
            if(leftArray[i] < rightArray[j]){
                nums[realArrayIndex++] = leftArray[i++];
            }
            else{
                nums[realArrayIndex++] = rightArray[j++];
            }
        }

        if(i < leftArrayLength){
         for(int k = i; k < leftArrayLength; k++){
            nums[realArrayIndex++] = leftArray[k];
         }
        }
        if(j < rightArrayLength){
         for(int k = j; k < rightArrayLength; k++){
            nums[realArrayIndex++] = rightArray[k];
         }
        }
    }

    void mergeSort(vector<int>& nums, int s, int e){
        //base case
        if(s >= e) return;
        //divide
        int mid = s+(e-s)/2;
        //left array
        mergeSort(nums,s,mid);
        //right array
        mergeSort(nums,mid+1,e);
        mergeArray(nums,s,e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        mergeSort(nums,start,end);
        return nums;
    }
};