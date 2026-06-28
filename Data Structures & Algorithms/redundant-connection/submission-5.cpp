class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltP(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findUltP(parent[node]);
    }

    bool makeUnion(int u, int v){
        int ultu = findUltP(u);
        int ultv  = findUltP(v);

        if(ultu == ultv){
            return true;
        }

        if(size[ultu]>size[ultv]){
            parent[ultu] = ultv;
            size[ultv]+=size[ultu];
        }
        else{
            parent[ultv] = ultu;
            size[ultu] +=size[ultv];
        }
        return false;

    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU *graph = new DSU(n+1);

        for(auto it:edges){
            int a = it[0], b = it[1];
            if(graph->makeUnion(a,b)) return it;
        }
        return {};
    }
};
