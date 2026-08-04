class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        // letter, index
        int l = 0, r = 0, ans = 0, n = s.length();

        for(r = 0;r<n;r++){
            int el = s[r];
            if(mpp.find(el)!=mpp.end()){
                l = max(l,mpp[el]+1);
            }

            mpp[el] = r;
            
            ans = max(ans,r-l+1);
        }
        return ans;
        
    }
};
