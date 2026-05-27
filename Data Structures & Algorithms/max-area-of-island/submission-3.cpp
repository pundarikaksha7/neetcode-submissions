class Solution {
public:
    int dfs(vector<vector<int>>&grid, vector<vector<int>> &visit, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(visit[i][j]) return 0;

        visit[i][j]=1;

        int cnt = 1;

        vector<int> dirs{-1,0,1};

        for(auto x:dirs){
            for(auto y: dirs){
                if(abs(x)==abs(y)) continue;

                int movex = i+x;
                int movey = j +y;

                if(movex<0 || movey<0 || movex>=m || movey>=n) continue;
                if(grid[movex][movey] && !visit[movex][movey]){
                    cnt+=dfs(grid,visit,movex,movey);
                }
            }
        }
        return cnt;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        int maxi = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n ; j++){
                if(grid[i][j] && !visit[i][j]){
                    maxi = max(maxi,dfs(grid,visit,i,j));
                }
            }
        }
        return maxi;
        
    }
};
