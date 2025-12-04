class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>dummyQ;
        int n = q.size();
        
        int i = 0;
        while(i < n/2){
            int temp = q.front(); q.pop();
            dummyQ.push(temp);
            i++;
        }
        
        while(!dummyQ.empty()){
            int temp = dummyQ.front(); dummyQ.pop();
            q.push(temp);
            temp = q.front(); q.pop();
            q.push(temp);
        }
    }
};