class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's algorithm

        int maxyet  = INT_MIN;
        int sum = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int num = nums[i];
            sum+=num;
            sum = max(sum,num);
            maxyet = max(maxyet,sum);
        }
        return maxyet;

    }
};
