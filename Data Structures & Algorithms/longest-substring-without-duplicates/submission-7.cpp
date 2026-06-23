class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();

        unordered_map<char,int> seen;

        int res = 0;

        while(l<n && r<n){
            char c = s[r];

            if(seen.find(c)!=seen.end()){
                int newl = seen[c]+1;
                while(l<n && l!=newl){
                    seen.erase(s[l]);
                    l++;
                }
            }
            seen[c] = r;
            res = max(res,r-l+1);
            r++;
        }
        return res;
        
    }
};
