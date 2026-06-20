class Solution {
public:
    int f (string &s, string &t, int i , int j,vector<vector<int>>&dp){
        int m = s.length(), n = t.length();
        
        if(i==m) return n-j;
        if(j==n) return m-i;

        if(dp[i][j]!=-1) return dp[i][j];

        int insert = INT_MAX, del = INT_MAX, replace = INT_MAX, move = INT_MAX;
        if(s[i]==t[j]) move = f(s,t,i+1,j+1,dp);
        insert = 1+f(s,t,i,j+1,dp);
        del = 1+f(s,t,i+1,j,dp);
        replace = 1+f(s,t,i+1,j+1,dp);

        return dp[i][j]=min({insert,del,replace,move});
    }
    int minDistance(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>>dp1(m+1,vector<int>(n+1,-1));
        return f(s,t,0,0,dp1);

        
    }
};
