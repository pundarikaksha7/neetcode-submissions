class Solution {
public:
    void f(vector<int>&nums,vector<int>curr,
    vector<vector<int>>&ans,int i){
        int n = nums.size();
        if(i==n){
            ans.push_back(curr);
            return ;
        }
        //take
        curr.push_back(nums[i]);
        f(nums,curr,ans,i+1);
        curr.pop_back();
        while(i+1<n && nums[i]==nums[i+1]){
            i++;
        }
        //nottake
        f(nums,curr,ans,i+1);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        f(nums,curr,ans,0);
        return ans;
    }
};
