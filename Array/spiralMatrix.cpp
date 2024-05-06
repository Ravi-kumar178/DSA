class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans;
        
        int length = m*n;
        int startCol = 0;
        int endCol = n-1;
        int startRow = 0;
        int endRow = m-1;

        int count = 0;
        while(count < length){
            for(int i = startCol; i <= endCol && (count < length); i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i = startRow; i <= endRow && (count < length); i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i = endCol; i >= startCol && (count < length); i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i = endRow; i >= startRow && (count < length); i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};