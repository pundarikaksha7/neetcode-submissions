class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mpp;

        mpp['{']='}';
        mpp['(']=')';
        mpp['[']=']';

        for(auto c:s){
            if(mpp.find(c)!=mpp.end()){
                st.push(c);
            }
            else{
                if(st.empty()==true || mpp.find(st.top())==mpp.end() || mpp[st.top()]!=c)return false;
                else st.pop();
            }
        }
        return st.empty();
        
    }
};
