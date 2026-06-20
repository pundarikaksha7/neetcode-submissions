class Solution {
public:
    int f(string &s, string &target, int i , int j,vector<vector<int>>&dp){
        int m = s.length(), n = target.length();
        if(j==n) return 1;
        if(i==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0, nottake = 0;
        if(s[i]==target[j]){
            take = f(s,target,i+1,j+1,dp);
        }
        nottake = f(s,target,i+1,j,dp);
        return dp[i][j] = take+nottake;
    }
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(s,t,0,0,dp);
    }
};
