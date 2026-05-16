class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp; // num, index
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int num=target-nums[i];
            if(mpp.find(num)!=mpp.end() && mpp[num]!=i)return {min(i,mpp[num]),max(i,mpp[num])};
        }
        return {0,0};
    }
};
