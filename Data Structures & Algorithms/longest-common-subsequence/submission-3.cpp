class Solution {
public:
    vector<vector<int>> dp;
    int f(string s, string t, int i, int j){
        int m = s.length(), n = t.length();

        if(i==m || j==n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j] = 1 + f(s,t,i+1,j+1);
        }

        int takes = f(s,t,i+1,j);
        int taket = f(s,t,i,j+1);

        return dp[i][j] = max(takes,taket);


    }
    int longestCommonSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        dp.resize(m,vector<int>(n,-1));
        return f(s,t,0,0);
    }
};
