class Solution {
public:
    bool f(vector<int>&nums, int i){
        int n = nums.size();
        if(i==n-1) return true;
        if(nums[i]==0) return false;

        int max_steps = nums[i];

        bool ans = false;

        for(int j = 1;j<=max_steps;j++){
            ans = ans || f(nums,i+j);
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        return f(nums,0);
        
    }
};
