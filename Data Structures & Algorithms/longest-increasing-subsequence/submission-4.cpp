class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(vector<int>&nums,int i, int prev){
        if(i>=n) return 0;

        int take = 0, nottake = 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev]) take = 1+f(nums,i+1,i);
        nottake = f(nums,i+1,prev);

        return dp[i][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(nums,0,-1);


        
    }
};
