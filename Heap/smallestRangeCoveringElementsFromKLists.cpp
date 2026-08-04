class Info {
public:
    int val;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) {
        this->val = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class Compare {
public:
    bool operator()(Info* a, Info* b) { return a->val > b->val; }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int totalRows = nums.size();
        priority_queue<Info*, vector<Info*>, Compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < totalRows; i++) {
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            Info* temp = new Info(element, i, 0);
            pq.push(temp);
        }

        int ans_start = mini, ans_end = maxi;

        while (!pq.empty()) {
            Info* front = pq.top();
            pq.pop();

            int frontData = front->val;
            int frontRow = front->rowIndex;
            int frontCol = front->colIndex;

            mini = frontData;

            if ((maxi - mini) < (ans_end - ans_start)) {
                ans_start = mini;
                ans_end = maxi;
            }

            int currentRowCol = nums[frontRow].size();

            if (frontCol + 1 < currentRowCol) {
                int element = nums[frontRow][frontCol + 1];
                maxi = max(maxi, element);
                Info* temp = new Info(element, frontRow, frontCol + 1);
                pq.push(temp);
            } 
            else {
                break;
            }
        }
        vector<int> ans(2,0);
        ans[0] = ans_start;
        ans[1] = ans_end;
        return ans;
    }
};