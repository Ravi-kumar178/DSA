class Solution {
public:
    void heapify(vector<int>& ans, int index){
        int childIndex = index;
        while(childIndex > 1){
            int parentIndex = childIndex/2;
            if(ans[parentIndex] < ans[childIndex]){
                swap(ans[parentIndex],ans[childIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }
    vector<int> mergeHeaps(vector<int>& heap1, vector<int>& heap2) {
        int n = heap1.size(), m = heap2.size();
        vector<int>ans(n+m+1);

        int index = 1;
        for(int i = 0; i < heap1.size(); i++){
            ans[index] = heap1[i];
            heapify(ans,index);
            index++;
        }

        int i = 0;
        while(i < m){
            ans[index] = heap2[i++];
            heapify(ans,index);
            index++;
        }
        vector<int>result(ans.begin()+1,ans.end());
        return result;
    }
};