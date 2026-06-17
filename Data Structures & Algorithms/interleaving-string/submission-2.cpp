class Solution {
public:
    bool f(string &s, string &t, string &target,
           int i, int j, int k,
           vector<vector<int>> &dp) {

        int m = s.length();
        int n = t.length();
        int mn = target.length();

        if(k == mn)
            return (i == m && j == n);

        if(dp[i][j] != -1)
            return dp[i][j];

        bool takei = false;
        bool takej = false;

        if(i < m && s[i] == target[k])
            takei = f(s, t, target, i + 1, j, k + 1, dp);

        if(j < n && t[j] == target[k])
            takej = f(s, t, target, i, j + 1, k + 1, dp);

        return dp[i][j] = (takei || takej);
    }

    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.length();
        int n = s2.length();
        int mn = s3.length();

        if(m + n != mn)
            return false;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return f(s1, s2, s3, 0, 0, 0, dp);
    }
};