class Solution {
public:
    int f(string &a, string &b, int i, int j,vector<vector<int>>&dp){
        int m = a.length();
        int n = b.length();

        if(i>=m) return 0;
        if(j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        //same letter
        if(a[i]==b[j]){
            return  1+f(a,b,i+1,j+1,dp);
        }
        return dp[i][j] = max(f(a,b,i+1,j,dp),f(a,b,i,j+1,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
        return f(a,b,0,0,dp);
        
    }
};
