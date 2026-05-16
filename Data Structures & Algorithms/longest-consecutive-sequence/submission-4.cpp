class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int len = 1;
        int maxlen = 0;

        if(n==0) return 0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==0)continue;
            if(nums[i]-nums[i-1]==1){
                len++;
            }
            else{
                maxlen = max(maxlen,len);
                len=1;
            }
        }
        maxlen = max(maxlen,len);
        return maxlen;
        
    }
    //2 3 4 4 5 10 20
};
