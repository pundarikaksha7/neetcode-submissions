class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three pointers ]
        // Dutch national flag algorithm

        int i = 0, l = 0, n = nums.size(), r = n-1;

        while(i<=r){
            int num = nums[i];

            if(num==0){
                swap(nums[l],nums[i]);
                l++;
            }
            else if(num == 2){
                swap(nums[r],nums[i]);
                r--;i--;
            }
            i++;
        }
    }
};