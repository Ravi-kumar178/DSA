class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>second;
        
        int size = q.size();
        int i = 0;
        while(i < size/2){
            int temp = q.front(); q.pop();
            second.push(temp);
            i++;
        }
        
        while(!second.empty()){
            int temp = second.front(); second.pop();
            q.push(temp);
            
            temp = q.front(); q.pop(); 
            q.push(temp);
        }
        return;
    }
};