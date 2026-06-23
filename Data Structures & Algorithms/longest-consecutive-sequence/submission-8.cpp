class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        unordered_set<int> st;

        for(auto it:nums) st.insert(it);

        for(int i = 0;i<n;i++){
            int num = nums[i];
            int cnt = 0;
            if(st.find(num-1)==st.end()){
                while(st.find(num+cnt)!=st.end()){
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }  
        return maxi;
    }
};
