class Solution {
public:
    map<pair<int,int>,int> dp;
    int f(vector<int>&nums, int target, int i){
        int n = nums.size();
        if(i==n && target == 0) return dp[{i,target}]= 1;
        if(i>=n) return 0;

        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        // add
        int add = f(nums,target-nums[i],i+1);
        int sub = f(nums,target+nums[i],i+1);

        return dp[{i,target}]= add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(nums,target,0);
        
    }
};
