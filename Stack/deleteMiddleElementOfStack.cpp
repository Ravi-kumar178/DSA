class Solution {
  public:
    void solve(stack<int>& s, int& pos){
        //base case
        if(pos == 1){
            s.pop();
            return;
        }
        //1 case
        int temp = s.top();
        s.pop();
        pos--;
        
        //recursive call
        solve(s,pos);
        //backtrack
        s.push(temp);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int size = s.size();
        int pos = size/2 + 1;
        solve(s,pos);
    }
};