class Solution {
public:
    bool f(string &s, vector<string>&wordDict,int i,vector<int>&dp){
        int n = s.length();
        if(i==n) return true;

        if(dp[i]!=-1) return dp[i];

        for(auto word: wordDict){
            int wordlen = word.length();
            if(i+ wordlen <=n && s.substr(i,wordlen)==word){
                if(f(s,wordDict,i+wordlen,dp)) return dp[i] =  true;
            }
        }
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        return f(s,wordDict,0,dp);
        
    }
};
