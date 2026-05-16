class Solution {
public:
    int f(vector<int>&nums, vector<int>&dp,int i){
        int n = nums.size();

        if(i==n) return 0 ;
        if(i==n-1) return nums[i];

        if(dp[i]!=-1) return dp[i];
        
        //rob
        int rob = nums[i]+f(nums,dp,i+2);
        //not rob
        int notrob = f(nums,dp,i+1);

        return dp[i] = max(rob,notrob);


    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,dp,0);
        
    }
};
