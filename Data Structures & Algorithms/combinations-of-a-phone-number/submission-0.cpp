class Solution {
public:
    void f(string &digits, vector<string>&ans,
    string curr,int i,
    unordered_map<char,string>&mpp){
        int n = digits.length();
        if(i==n){
            ans.push_back(curr);
            return ;
        }
        char current = digits[i];
        //take the current letter 
        for(auto c:mpp[current]){
            curr+=c;
            f(digits,ans,curr,i+1,mpp);
            curr.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp;
        if(digits.length()==0) return {};
        vector<string> ans;
        mpp['2']="abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        f(digits,ans,"",0,mpp);
        return ans;
        
    }
};
