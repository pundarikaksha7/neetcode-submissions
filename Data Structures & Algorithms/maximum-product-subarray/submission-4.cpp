class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res  = nums[0];
        int maxcnt = 1,mincnt = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int num = nums[i];

            int tmp = maxcnt * num;

            maxcnt = max({maxcnt*num, mincnt * num, num});
            mincnt = min({tmp, mincnt * num, num});

            res = max({res,maxcnt,mincnt});
        }
        return res;
        
    }
};
