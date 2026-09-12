class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>&nums,int target,int i,vector<int>state){
        if(target==0){
            ans.push_back(state);
            return;
        }
        int n = nums.size();
        if(i==n) return;

        if(nums[i]<=target){
            state.push_back(nums[i]);
            f(nums,target-nums[i],i,state);
            state.pop_back();
        }
        f(nums,target,i+1,state);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> state;
        ans.resize(0);
        f(nums,target,0,state);
        return ans;
    }
};
