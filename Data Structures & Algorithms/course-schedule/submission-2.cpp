class Solution {
public:
    bool cycle(vector<vector<int>>&adj,vector<int>&visit,vector<int> &pathvisit,
    int node){
        visit[node] = 1;
        pathvisit[node] = 1;
        for(auto it:adj[node]){
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
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> visit(numCourses);
        vector<int> pathvisit(numCourses);

        for(auto it:pre){
            int parent = it[1];
            int child = it[0];

            adj[parent].push_back(child);
        }

        for(int i = 0;i<numCourses;i++){
            if(!visit[i] && cycle(adj,visit,pathvisit,i)) return false;
        }
        return true;



    }
};
