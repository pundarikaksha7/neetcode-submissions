class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> st;
        vector<int>ans(n);

        for(int i = 0;i<n;i++){
            int temp = temps[i];
            
            while(!st.empty() && temps[st.top()]<temp){
                int lastindex = st.top();
                st.pop();
                ans[lastindex] = i-lastindex;
            }
            st.push(i);
            
        }
        return ans;
        
    }
};
