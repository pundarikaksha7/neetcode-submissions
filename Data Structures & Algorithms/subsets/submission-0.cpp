class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>v,vector<vector<int>>&ans){
        int n = nums.size();
        if(i>=n){
            ans.push_back(v);
            return ;
        }
        //take
        v.push_back(nums[i]);
        f(i+1,nums,v,ans);
        v.pop_back();
        f(i+1,nums,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        f(0,nums,v,ans);
        return ans;
        
    }
};
