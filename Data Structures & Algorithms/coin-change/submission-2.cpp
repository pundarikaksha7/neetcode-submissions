class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int f(vector<int>&coins,int amount,int i){
        if(amount == 0) return 0;
        if(i>=n || amount<0) return INT_MAX;

        int take = INT_MAX, nottake = INT_MAX;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int res = f(coins,amount-coins[i],i);

        if(amount-coins[i]>=0 && res!=INT_MAX) take = 1+res;
        nottake = f(coins,amount,i+1);

        return dp[i][amount] = min(take,nottake);
 
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));

        return f(coins,amount,0)==INT_MAX?-1:f(coins,amount,0);
        
    }
};
