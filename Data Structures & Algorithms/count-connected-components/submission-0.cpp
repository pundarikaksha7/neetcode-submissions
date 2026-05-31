class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&visit, int node){
        visit[node] = 1;
        for(auto it:adj[node]){
            if(!visit[it]){
                dfs(adj,visit,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visit(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!visit[i]){
                cnt++;
                dfs(adj,visit,i);
            }
        }
        return cnt;

    }
};
