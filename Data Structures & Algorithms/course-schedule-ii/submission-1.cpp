class Solution {
public:
    bool cycle(vector<vector<int>>&adj,vector<int>&visit,vector<int>&pathvisit,
    int node){
        visit[node] = 1;
        pathvisit[node] = 1;

        for(auto it: adj[node]){
            if(!visit[it]){
                if(cycle(adj,visit,pathvisit,it)) return true;
            }
            else{
                if(pathvisit[it]) return true;
            }
        }

        pathvisit[node] = 0;
        return false;
    }

    stack<int> sorted;
    void toposort(vector<vector<int>>&adj, vector<int>&visit,int node){
        visit[node] = 1;

        for(auto it:adj[node]){
            if(!visit[it]){
                toposort(adj,visit,it);
            }
        }
        sorted.push(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> visit(n+1);
        vector<int> pathvisit(n+1);

        vector<vector<int>> adj(n+1);

        for(auto it:pre){
            int parent = it[1], child = it[0];

            adj[parent].push_back(child);
        }
        for(int i =0;i<n;i++){
            if(!visit[i] && cycle(adj,visit,pathvisit,i)) return {};
        }
        vector<int> visited(n+1);

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                toposort(adj,visited,i);
            }
        }
        vector<int> ans;
        while(!sorted.empty()){
            int node = sorted.top();
            sorted.pop();
            ans.push_back(node);
        }
        return ans;

        
    }
};
