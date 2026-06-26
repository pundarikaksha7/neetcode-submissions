class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, n = nums.size(), r = n-1, mid = 0;

        if(target<nums[0]) return 0;
        if(target>nums[n-1]) return n;

        while(l<=r){
            mid = l+(r-l)/2;

            int ele = nums[mid];

            if(ele == target) return mid;

            if(mid>=1 && ele>target && nums[mid-1]<target) return mid;

            if(target<ele) r = mid-1;
            else l=mid+1;
        }
        return mid;
        
    }
};