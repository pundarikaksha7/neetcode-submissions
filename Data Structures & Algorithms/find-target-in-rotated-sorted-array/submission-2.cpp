class Solution {
public:
    int bs(vector<int>&nums, int l, int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;

            if(nums[mid]==target) return mid;
            if(target>nums[mid]) l = mid+1;
            else r= mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find pivot
        // two pass bs

        int l = 0, n = nums.size(), r = n-1;

        int pivot = -1;

        while(l<r){
            int mid = l+(r-l)/2;

            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r= mid;
            }
            
        }
        pivot = l;
        int res = -1;

        if(!pivot) return bs(nums,0,n-1,target);
        int findleft  = bs(nums,0,pivot-1,target);
        int findright = bs(nums,pivot,n-1,target);
        return findleft==-1?findright:findleft;


    }
};

// 5 1 2 3 4
