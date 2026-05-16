class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=1;
        suffix[n-1]=1;

        //prefix 1 1 2 8
        //suffix 48   24  6   1

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(auto c:prefix)cout<<c<<" ";
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(auto c:suffix)cout<<c<<" ";


        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;

    }
};
