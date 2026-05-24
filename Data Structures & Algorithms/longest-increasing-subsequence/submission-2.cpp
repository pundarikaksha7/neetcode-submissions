class Solution {
public:
    int f(vector<int>&nums, int i, int prev,vector<vector<int>>&dp){
        int n = nums.size();

        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int maxi = 0;

        for(int j = i;j<n;j++){
            int num = nums[j];
            int cnt = 0;
            if(prev == -1 || num>nums[prev]){
                cnt = 1+ f(nums,j+1,j,dp);
            }
            maxi = max(maxi,cnt);
        }
        return dp[i][prev+1] = maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
    }
};
