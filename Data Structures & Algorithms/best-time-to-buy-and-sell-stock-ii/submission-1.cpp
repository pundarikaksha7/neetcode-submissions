class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(vector<int>&prices,int i, bool holding){
        if(i>=n) return 0;

        int buy = 0, sell = 0;

        if(dp[i][holding]!=-1) return dp[i][holding];

        if(holding){
            buy = f(prices,i+1,holding);
            sell = prices[i] + f(prices,i+1,0);
        }
        else{
            buy = -prices[i] + f(prices,i+1,1);
            sell = f(prices,i+1,holding);
        }

        return dp[i][holding] = max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n,vector<int>(2,-1));

        return f(prices,0,0);
        
    }
};