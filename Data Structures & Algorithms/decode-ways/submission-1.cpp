class Solution {
public:
    int f(string &s, int i, vector<int>& dp) {
        int n = s.length();

        if (i == n) return 1;

        if (dp[i] != -1) return dp[i];

        if (s[i] == '0') return dp[i] = 0;

        int ans = f(s, i + 1, dp);

        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26) {
                ans += f(s, i + 2, dp);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n, -1);

        return f(s, 0, dp);
    }
};