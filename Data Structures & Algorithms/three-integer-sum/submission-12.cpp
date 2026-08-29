class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        vector<vector<int>> res;

        // -4 -1 -1 0 1 2
        for(int i = 0;i<n;i++){
            int target = -nums[i];

            if(target<0) break;

            int l = i+1;
            int r = n-1;

            while(l<r){
                int a = nums[l];
                int b = nums[r];

                if(a+b<target){
                    l++;
                }
                else if(a+b>target){
                    r--;
                }
                else{
                    //a+b==target
                    res.push_back({a,b,-target});
                    int iter = l;
                    while(iter<n && nums[iter]==nums[l]){
                        iter++;
                    }
                    if(iter<n) l = iter;
                    else break;
                }
            }
            int iter = i;
            while(iter<n && nums[iter]==nums[i]){
                iter++;
            }
            if(iter<n)i = iter-1;
            else break;

        }
        return res;
    }
};
