class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int l=0,r=0;
        int maxi=0;
        int n=s.length();
        int maxf=0;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);

            while((r-l+1)-maxf>k){
                mpp[s[l]]--;
                l++;
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
        
    }
};
