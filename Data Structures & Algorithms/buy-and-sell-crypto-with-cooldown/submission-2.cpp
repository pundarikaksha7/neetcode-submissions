class Solution {
public:
    int f(vector<int>&prices, int i, int canbuy,vector<vector<int>>&dp){
        int n = prices.size();

        if(i>=n) return 0;

        //buy now cannot sell if havent bought

        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int buyi = 0;
        if(canbuy == 1) buyi = -prices[i] + f(prices,i+1,0,dp);
        int skip = f(prices,i+1,canbuy,dp);

        //sell now
        int selli = 0;
        if(canbuy==0) selli = prices[i]+ f(prices,i+2,1,dp);

        return dp[i][canbuy] = max({buyi,selli,skip});
    }
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>> dp(m,vector<int>(2,-1));
        return f(prices, 0 , 1,dp);
        
    }
};
