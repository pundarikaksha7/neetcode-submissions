class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int> &visit,
    vector<int>&pathvisit,int i){
        visit[i]=1;
        pathvisit[i]=1;

        for(auto it:adj[i]){
            if(!visit[it]){
                if(dfs(adj,visit,pathvisit,it)) return true;
            }
            else{
                if(pathvisit[it]) return true;
            }
        }
        pathvisit[i]=0;
        return false;
    }
    void topologicalSort(vector<vector<int>>&adj, vector<int>&visit,int node,
    stack<int>&st){
        visit[node] = 1;
        for(auto it:adj[node]){
            if(!visit[it]){
                topologicalSort(adj,visit,it,st);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int nums, vector<vector<int>>& pre) {
        vector<vector<int>> adj (nums);
        vector<int> visit(nums);
        vector<int> pathvisit(nums);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<nums;i++){
            if(!visit[i] && dfs(adj,visit,pathvisit,i)) return {};
        }
        vector<int>topovisit(nums);
        stack<int> st;
        for(int i = 0;i<nums;i++){
            if(!topovisit[i]) topologicalSort(adj,topovisit,i,st);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

        // adjacency created

        
    }
};
