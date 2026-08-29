class Solution {
public:
    vector<int> dp;
    bool f(string s,vector<string> &wordDict,int i){
        int n = s.length();

        if(i==n) return true;

        if(dp[i]!=-1) return dp[i];

        for(auto word:wordDict){
            int wordlen = word.size();
            string str = s.substr(i,wordlen);

            if(str == word){
                if(f(s,wordDict,i+wordlen)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),-1);
        return f(s,wordDict,0);
    }
};
