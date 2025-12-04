class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k > q.size()) return q;
        //init
        stack<int>st;
        int p = k;
        
        //reverse first k element
        while(p--){
            int temp = q.front(); q.pop();
            st.push(temp);
        }
        
        //push stack element into q
        while(!st.empty()){
            int temp = st.top(); st.pop();
            q.push(temp);
        }
        
        for(int i = 0; i < q.size()-k; i++){
            int temp = q.front(); q.pop(); q.push(temp);
        }
        return q;
        
    }
};