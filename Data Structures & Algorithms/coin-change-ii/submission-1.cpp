class Solution {
public:
    int f(vector<int>&coins, int amount, int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(amount == 0) return dp[i][amount] = 1;
        if(i>=n || amount<0) return 0;

        int take = 0, nottake = 0;
        if(dp[i][amount]!=-1) return dp[i][amount];

        if(amount-coins[i]>=0) take = f(coins,amount-coins[i],i,dp);

        nottake = f(coins,amount,i+1,dp);

        return dp[i][amount] = take+ nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n,vector<int>(amount+1,-1));
        return f(coins,amount,0,dp);
    }
};
