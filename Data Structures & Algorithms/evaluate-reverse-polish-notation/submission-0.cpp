class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c:tokens){
            if(c!="+" && c!="-" &&c!="*" && c!="/"){
                st.push(stoi(c));
            }
            else{
                if(c=="+"){
                    int ans;
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    ans=a+b;
                    st.push(ans);
                }
                else if(c=="-"){
                    int ans;
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    ans=b-a;
                    st.push(ans);

                }
                else if(c=="*"){
                    int ans;
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    ans=a*b;
                    st.push(ans);
                }
                else{
                    int ans;
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    ans=b/a;
                    st.push(ans);
                }
            }
        }
        return st.top();
        
    }
};
