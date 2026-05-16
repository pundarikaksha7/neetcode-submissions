class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto c:nums){
            if(st.find(c)!=st.end())return true;
            st.insert(c);
        }
        return false;
        
    }
};