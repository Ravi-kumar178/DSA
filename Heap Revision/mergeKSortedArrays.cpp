class Info{
  public:
  int data;
  int rowIndex;
  int colIndex;
  
  Info(int val, int row, int col){
      this->data = val;
      this->rowIndex = row;
      this->colIndex = col;
  }
};

class Compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<Info*,vector<Info*>,Compare>minHeap;
        vector<int>ans;
        
        int row = mat.size();
        for(int i = 0; i < row; i++){
            Info* temp = new Info(mat[i][0],i,0);
            minHeap.push(temp);
        }
        
        //main logic
        while(!minHeap.empty()){
            Info* front = minHeap.top(); minHeap.pop();
            int frontData = front->data;
            int frontRowIndex = front->rowIndex;
            int frontColIndex = front->colIndex;
            
            ans.push_back(frontData);
            
            int totalCols = mat[frontRowIndex].size();
            
            if(frontColIndex+1 < totalCols){
                Info* temp = new Info(mat[frontRowIndex][frontColIndex+1],frontRowIndex,frontColIndex+1);
                minHeap.push(temp);
            }
        }
        return ans;
    }
};