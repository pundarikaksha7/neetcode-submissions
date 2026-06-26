class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(nums[mid] == target) return mid;
            if(target<nums[mid])r--;
            else l++;
        }
        return -1;
    }
};
