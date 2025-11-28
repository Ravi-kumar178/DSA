class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        if(mat.size() == 1) return 0;
        
        stack<int>st;
        for(int i = 0; i < mat.size(); i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int A = st.top(); st.pop();
            int B = st.top(); st.pop();
            
            if(mat[A][B] == 1){
                //discard a
                st.push(B);
            }
            else{
                //discard b
                st.push(A);
            }
        }
        
        int num = st.top();
        //col check
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][num] == 0) return -1;
        }
        //row check
        for(int i = 0; i < mat.size(); i++){
            if(i!=num && mat[num][i] != 0) return -1;
        }
        return num;
    }
};