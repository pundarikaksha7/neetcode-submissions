class Solution {
public:
    vector<int> dp;
    int f(string s, int i){
        int n = s.length();
        if(i>=n) return 1;
        if(s[0]=='0') return 0;

        int takeone = 0, taketwo = 0;

        if(dp[i]!=-1) return dp[i];

        if(s[i]!='0' && s[i+1]!='0')takeone = f(s,i+1);
        if(i<n-1) {
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num>=10 && num<=26)taketwo = f(s,i+2);
        }
        return dp[i] = takeone + taketwo;
    }
    int numDecodings(string s) {
        dp.resize(s.length(),-1);
        return f(s,0);
    }
};
