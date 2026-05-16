class Solution {
public:
    void f(vector<int>&cands, int i,vector<int> v,
    vector<vector<int>>&ans, int target){
        int n = cands.size();
        if(i==n){
            if(target==0){
                ans.push_back(v);
            }
            return ;
        }
        //take
        if(cands[i]<=target){
            v.push_back(cands[i]);
            f(cands,i+1,v,ans,target-cands[i]);
            v.pop_back();
        }
        while(i+1<n && cands[i]==cands[i+1]){
            i++;
        }
        f(cands,i+1,v,ans,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& cands, int target) {
        vector<int> v;
        vector<vector<int>>ans;
        sort(cands.begin(),cands.end());
        f(cands,0,v,ans,target);
        // vector<vector<int>>ans(st.begin(),st.end());

        return ans;
    }
};
