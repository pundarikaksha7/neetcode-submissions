class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<pair<int,int>> st;
        vector<int> res(n);

        st.push({t[0],0});
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top().first<t[i]){
                int prevtemp=st.top().first;
                int index=st.top().second;
                res[index]=i-index;
                st.pop();
            }
            st.push({t[i],i});
        }
        while(!st.empty()){
                int prevtemp=st.top().first;
                int index=st.top().second;
                res[index]=0;
                st.pop();
        }
        return res;
        
    }
};
