class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n =nums.size();

        for(auto c:nums){
            mpp[c]=0;
        }

        int maxcnt = 0;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int cnt = 0;
            if(mpp.find(num-1)!=mpp.end() && mpp[num-1]!=0){
                cnt = mpp[num-1]+1;
                mpp[num]=cnt;
                maxcnt = max(maxcnt,cnt);
                continue;
            }
            while(mpp.find(num)!=mpp.end()){
                cnt++;
                num--;
            }
            mpp[nums[i]]=cnt;
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;

         
        
    }
};
