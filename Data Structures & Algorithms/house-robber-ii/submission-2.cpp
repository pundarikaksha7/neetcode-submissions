class Solution {
public:

    int f(vector<int>& nums,
          vector<vector<int>>& dp,
          int i,
          bool first){

        int n = nums.size();

        if(i >= n) return 0;

        if(i == n-1){
            if(first) return 0;
            return nums[i];
        }

        if(dp[i][first] != -1)
            return dp[i][first];

        int rob = nums[i] + f(nums, dp, i+2, first);

        // if robbing first house
        if(i == 0)
            rob = nums[i] + f(nums, dp, i+2, true);

        int notrob = f(nums, dp, i+1, first);

        return dp[i][first] = max(rob, notrob);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<vector<int>> dp(n, vector<int>(2,-1));

        return f(nums, dp, 0, false);
    }
};