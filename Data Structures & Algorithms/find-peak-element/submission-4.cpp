class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = nums.size();

        if(n==1) return 0;


        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid ==0){
                if(nums[mid]>nums[mid+1]) return mid;
                else return mid+1;
            }
            if(mid==n-1){
                if(nums[mid]>nums[mid-1])return mid;
                else return mid-1;
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]<nums[mid+1])l=mid+1;
            else r = mid-1;
        }
        return r;
        
    }
};