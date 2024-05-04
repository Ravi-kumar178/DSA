class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int index = 1;
        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                a[index] = a[i];
                index++;
            }
        }
        return index;
    }
};