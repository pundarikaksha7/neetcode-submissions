class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n  = nums.size(), currsum = 0;
        bool res = false;


        unordered_map<int,int> mpp;
        mpp[0] = -1;

        for(int i = 0;i<n;i++){
            int num = nums[i];
            currsum+=num;

            if(mpp.find(currsum%k)==mpp.end()) mpp[currsum%k] = i;
            else{
                if(i-mpp[currsum%k]>1) return true;
            }
        }
        return false;
    }
};