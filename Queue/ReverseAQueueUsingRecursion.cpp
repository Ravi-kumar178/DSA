class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        //base case
        if(q.empty()) return;
        
        int temp = q.front();
        q.pop();
        
        reverseQueue(q);
        q.push(temp);
    }
};