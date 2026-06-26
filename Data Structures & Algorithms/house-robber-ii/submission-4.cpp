class Solution {
public:
    int first = 1;
    vector<vector<int>>dp;
    int f(vector<int>&nums,int i){
        int n = nums.size();

        if(i>=n) return 0;
        if(first && i==n-1) return 0;

        if(dp[i][first]!=-1) return dp[i][first];
        int take = 0 , nottake = 0;

        if(i==0){
            if(first){
                take = nums[i] + f(nums,i+2);
            }
            else{
                take = 0;
            }
            nottake = f(nums,i+1);
        }
        else{
            take = nums[i] + f(nums,i+2);
            nottake = f(nums,i+1);
        }

        return dp[i][first] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        dp.resize(nums.size(),vector<int>(2,-1));
        int robbedfirst = f(nums,0);
        first = 0;
        int missedfirst = f(nums,1);

        return max(robbedfirst,missedfirst);
        
    }
};
