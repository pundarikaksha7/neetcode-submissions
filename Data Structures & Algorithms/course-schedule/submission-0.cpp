class Solution {
public:

    bool dfs(vector<vector<int>>&adj, int i, vector<int>&visit,
    vector<int>&pathvisit){
        visit[i]=1;
        pathvisit[i]=1;

        for(auto it:adj[i]){
            if(!visit[it]){
                if(dfs(adj,it,visit,pathvisit)) return true;
            }
            else{
                if(pathvisit[it]) return true;
            }
        }
        pathvisit[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> visit(n,0);
        vector<vector<int>> adj(n);
        vector<int> pathvisit(n);

        for(auto c:pre){
            adj[c[1]].push_back(c[0]);
        }
        for(int i =0;i<n;i++){
            if(dfs(adj,i,visit,pathvisit)) return false;
        }
        return true;
    }
};
