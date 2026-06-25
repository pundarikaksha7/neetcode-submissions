class Solution {
public:
    bool cycle(vector<vector<int>>&adj,vector<int>&visit,int node){
        visit[node] = 1;

        for(auto it:adj[node]){
            if(!visit[it]){
                if(cycle(adj,visit,it)) return true;
            }
            else{
                return true;
            }
        }
        visit[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> visit(numCourses);

        for(auto it:pre){
            int parent = it[1];
            int child = it[0];

            adj[parent].push_back(child);
        }

        for(int i = 0;i<numCourses;i++){
            if(cycle(adj,visit,i)) return false;
        }
        return true;



    }
};
