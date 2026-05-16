class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n =nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        for(int i =0;i<n;i++){
            int findnum = target-nums[i];
            if(mpp.find(findnum)!=mpp.end()){
                int a = mpp[findnum];
                int b = i;
                if(a==b)continue;
                return {min(a,b),max(a,b)};
            }
        }
        return {0,0};
    }
};
