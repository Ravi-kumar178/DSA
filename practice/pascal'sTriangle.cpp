class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0; i < numRows; i++){
            vector<int>rows;
            for(int j = 0; j <= i; j++){
                if(i == 0 || j == 0){
                    rows.push_back(1);
                }
                else{
                   if(j < ans[i-1].size()){
                     rows.push_back(ans[i-1][j-1]+ans[i-1][j]);
                   }
                   else{
                    rows.push_back(1);
                   }
                }
            }
            ans.push_back(rows);
        }
        return ans;
    }
};