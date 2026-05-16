class Solution {
public:
    void f(int i, vector<int>&nums, int target, vector<int> v,
    vector<vector<int>>&ans){
        int n = nums.size();
        if(i==n){
            if(target==0){
                ans.push_back(v);
            }
            return ;
        }
        //take
        if(nums[i]<=target){
            v.push_back(nums[i]);
            f(i,nums,target-nums[i],v,ans);
            v.pop_back();
        }
        f(i+1,nums,target,v,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        f(0,nums,target,v,ans);
        return ans;
    }
};
