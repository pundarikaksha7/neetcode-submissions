class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto c:nums){
            mini=min(c,mini);
            maxi=max(c,maxi);
        }
        for(auto c:nums){
            st.insert(c);
        }
        int len=0;
        int maxlen=0;
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)!=st.end()){
                len++;
            }
            else{
                maxlen=max(maxlen,len);
                len=0;
            }
        }
        maxlen=max(maxlen,len);
        return maxlen;
        
    }
};
