class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size() - 1;
        queue<int> q;

        for (int i = 0; i <= n; i++) {
            q.push(tickets[i]);
        }

        int time = 0, i = k;

        while (!q.empty()) {

            if (q.size() == 1) {
                time += q.front();
                break;
            }

            if (i == 0 && q.front() == 1) {
                time += 1;
                break;
            }

            if (q.front() != 1) {
                int front = q.front();
                q.pop();
                q.push(front - 1);
            } else {
                q.pop();
                n = n - 1;
            }

            if (i == 0)
                i = n;
            else
                i--;

            time += 1;
        }
        return time;
    }
};