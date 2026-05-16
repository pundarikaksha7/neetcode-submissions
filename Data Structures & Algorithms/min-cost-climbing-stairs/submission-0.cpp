class Solution {
public:
    int f(vector<int>&cost, vector<int>&dp,int i){
        int n = cost.size();

        if(i==n) return 0;
        if(i==n-1) return cost[i];
        if(dp[i]!=0) return dp[i];

        int takeone = cost[i] + f(cost,dp,i+1);
        int taketwo = cost[i] + f(cost,dp,i+2);

        return dp[i] = min(takeone,taketwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size());
        return min(f(cost,dp,0),f(cost,dp,1));
        
    }
};
