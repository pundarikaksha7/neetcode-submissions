class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;

        int n = nums.size(), cnt = 0, currsum = 0;
        prefix[0] = 1;

        for(int i = 0;i<n;i++){
            currsum+=nums[i];
            cnt += prefix[currsum-k];
            prefix[currsum]++;
        }
        return cnt;
    }
};