class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &nums, int i, int prev){
        int n = nums.size();

        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take = 0, skip = 0;

        skip = f(nums,i+1,prev);

        if(prev==-1 || nums[prev]<nums[i]){
            take = 1 + f(nums,i+1,i);
        }

        return dp[i][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(nums,0,-1);
    }
};
