class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        unordered_map<char,int> mpp;
        if(s.length()==0) return 0;
        int maxi=1;
        int len=0;

        while(r<s.length()){
            char c=s[r];
            if(mpp.find(c)==mpp.end()){
                len++;
            }
            else{
                l=max(mpp[c]+1,l);
            }
            maxi=max(maxi,r-l+1);

            mpp[c]=r;
            r++;

        }
        
        return maxi;
        
    }
};
