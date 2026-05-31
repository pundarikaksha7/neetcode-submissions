class Solution {
public:
    // detect cycle in undirected graph?
    bool cycle(vector<vector<int>>&adj, vector<int>&visit,int node,
    int parent){
        visit[node] = 1;
        for(auto it:adj[node]){
            if(!visit[it]){
                if(cycle(adj,visit,it,node)) return true;
            }
            else{
                if(it!=parent)return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visit(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(cycle(adj,visit,0,-1)) return false;
        for(int i = 0;i<n;i++) if(visit[i]==0) return false;
        return true;

    }
};
