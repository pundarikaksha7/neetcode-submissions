class Solution {
public:
    void f(vector<int>&nums, vector<vector<int>> &ans,
    vector<int> &path,
    vector<int>curr, int i){
        int n = nums.size();
        if(curr.size()==n){
            ans.push_back(curr);
            return ;
        }
        if(i==n) return ;
        //take
        // nottake
        for(int x=0;x<n;x++){
            //take
            if(path[x]==0){
                curr.push_back(nums[x]);
                path[x]=1;
                f(nums,ans,path,curr,x);
                curr.pop_back();
                path[x]=0;
            }
        }
               
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
    
        vector<int> path(n);
        vector<int> curr;
        f(nums,ans,path,curr,0);
        return ans;
        
    }
};
