class Solution {
public:
    vector<int>dp;
    int f(vector<int>&cost,int i){
        int n = cost.size();

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int takeone = cost[i] + f(cost,i+1);
        int taketwo = cost[i] + f(cost,i+2);

        return dp[i] = min(takeone,taketwo);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,-1);

        return min(f(cost,0),f(cost,1));
    }
};
