class Solution {
public:
    bool well(string &s){
        stack<char> st;
        for(auto c:s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void f(int n,int leftcnt, int rightcnt,
     string curr,vector<string>&ans, int i){
        if(i==n){
            if(well(curr)) ans.push_back(curr);
            return ;
        }
        //take left
        if(leftcnt>0){
            curr+='(';
            f(n,leftcnt-1,rightcnt,curr,ans,i+1);
            curr.pop_back();
        }
        if(rightcnt>0){
            curr+=')';
            f(n,leftcnt,rightcnt-1,curr,ans,i+1);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        f(2*n,n,n,curr,ans,0);
        return ans;
        
    }
};
