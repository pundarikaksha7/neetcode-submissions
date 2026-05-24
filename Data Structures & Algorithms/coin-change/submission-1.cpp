class Solution {
public:
    int f (vector<int>&coins, int amount, int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(amount == 0) return 0;
        if(i==n) return INT_MAX;
        
        if(dp[i][amount]!=-1) return dp[i][amount];

        int mini = INT_MAX;
        

        for(int j = i ;j<n;j++){
            int num = INT_MAX;
            int coin = coins[j];
            if(amount-coin>=0) num = f(coins,amount-coin,j,dp);
            if(num!=INT_MAX) num++;
            mini = min(mini,num);
        }

        return dp[i][amount] = mini;
        //10 5 1.  12

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = f(coins,amount,0,dp);
        return ans==INT_MAX?-1:ans;
        
    }
};
