class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        for(int i = 0;i<n; i++){
            mpp[target-nums[i]] = i;
        }
        for(int i = 0;i<n;i++){
            int num = nums[i];

            if(mpp.find(num)!=mpp.end() && mpp[num]!=i){
                return {min(i,mpp[num]),max(i,mpp[num])};
            }
        }
        return {};
        
    }
};
