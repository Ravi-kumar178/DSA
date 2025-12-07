class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }

        int j = k;
        while(q.size() > 1){
            while(j > 1){
                int temp = q.front(); q.pop();
                q.push(temp);
                j--;
            }
            q.pop();
            j = k;
        }
        return q.front();
    }
};