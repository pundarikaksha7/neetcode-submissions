class Solution {
public:
    int f(vector<int>&prices, int i, int previ,vector<vector<int>>&dp){
        int n = prices.size();

        if(i>=n) return 0;

        //buy now cannot sell if havent bought

        if(dp[i][previ+1]!=-1) return dp[i][previ+1];
        int buyi = 0;
        if(previ == -1) buyi = -prices[i] + f(prices,i+1,i,dp);
        int skip = f(prices,i+1,previ,dp);

        //sell now
        int selli = 0;
        if(previ!=-1) selli = prices[i]+ f(prices,i+2,-1,dp);

        return dp[i][previ+1] = max({buyi,selli,skip});
    }
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return f(prices, 0 , -1,dp);
        
    }
};
