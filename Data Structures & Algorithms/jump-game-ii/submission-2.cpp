class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jumps = 0;
        int n = nums.size();

        while(r<n-1){
            int farthest = r;
            for(int i = l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l=r;
            r=farthest;
            jumps++;
        }
        return jumps;
        
    }
};
