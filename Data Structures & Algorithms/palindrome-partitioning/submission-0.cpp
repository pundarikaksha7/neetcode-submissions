class Solution {
public:
    bool isp1(vector<string>&v){
        for(auto s:v)
        {
            int j = s.length()-1;
            int i = 0;

            while(i<j){
                if(s[i]!=s[j])return false;
                i++;j--;
            }
        }
        return true;


    }
    bool isp2(string &s){
        int i = 0;
        int j = s.length()-1;

        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void f(vector<vector<string>>&ans,
    string &s,
    vector<string>curr,
    string currstring,
    int i){
        int n = s.length();
        if(i==n){
            if(currstring == "") return;
            if(isp2(currstring)){
                curr.push_back(currstring);
                ans.push_back(curr);
            }
            
            return;
        }

        //take the char in the currstring
        currstring+=s[i];

        f(ans,s,curr,currstring,i+1);

        //break the currstring and start a new
        if(isp2(currstring)){
            curr.push_back(currstring);
            f(ans,s,curr,"",i+1);
        }
        

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string currstring= "";
        vector<string> curr;
        f(ans,s,curr,currstring,0);
        return ans;
    }
};
