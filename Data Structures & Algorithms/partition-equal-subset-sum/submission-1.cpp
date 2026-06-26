class Solution {
public:
    vector<vector<int>> dp;
    int n;
    bool f(vector<int>&nums,int i,int sum){
         if(sum==0) return 1;
         if(i>=n || sum<0) return false;

         int take  = 0, nottake = 0;

         if(dp[i][sum]!=-1) return (bool)dp[i][sum];
         if(sum-nums[i]>=0) take = f(nums,i+1,sum-nums[i]);
         nottake = f(nums,i+1,sum);

         return dp[i][sum] = (int)take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(auto it:nums)sum+=it;

        if(sum%2!=0) return false;
        sum/=2;
        dp.resize(n,vector<int>(sum+1,-1));

        return f(nums,0,sum);
        
    }
};
