class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> pos(n + 1);

        vector<int> digit;
        vector<long long> preSum(1, 0);
        vector<long long> preNum(1, 0);

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            pos[i] = cnt;

            if (s[i] != '0') {

                int d = s[i] - '0';

                digit.push_back(d);

                cnt++;

                preSum.push_back(preSum.back() + d);

                preNum.push_back((preNum.back() * 10 + d) % MOD);
            }
        }

        pos[n] = cnt;

        vector<long long> pow10(cnt + 1, 1);

        for (int i = 1; i <= cnt; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = pos[l];
            int R = pos[r + 1];

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long num =
                (preNum[R] -
                 preNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum =
                preSum[R] - preSum[L];

            ans.push_back(num * (sum % MOD) % MOD);
        }

        return ans;
    }
};