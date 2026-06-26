class Solution {
public:
    vector<int> dp;
    int f(vector<int>&nums, int i){
        int n = nums.size();

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int take = nums[i] + f(nums,i+2);
        int nottake = f(nums,i+1);

        return dp[i] = max(take,nottake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);

        return f(nums,0);
        
    }
};
