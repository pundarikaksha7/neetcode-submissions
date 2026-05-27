class Solution {
public:
    bool f(vector<int>&nums, int sum,int i,vector<vector<int>>&dp){
        int n = nums.size();
        if(sum<0) return false;
        if(sum == 0) return  true;
        if(i>=n) return false;
        

        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take = 0;
        if(sum-nums[i]>=0) take = f(nums,sum-nums[i],i+1,dp);
        bool nottake = f(nums,sum,i+1,dp);

        return dp[i][sum] = take || nottake;

        //take i 


    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto c:nums) sum+=c;
        if(sum%2!=0) return false;

        
        
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        sum/=2;
        return f(nums,sum,0,dp);
        
    }
};
