class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums)st.insert(it);

        int ans = 0;

        for(auto it:nums){
            int cnt = 0;

            if(st.find(it-1)==st.end()){
                while(st.find(it++)!=st.end()){
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
