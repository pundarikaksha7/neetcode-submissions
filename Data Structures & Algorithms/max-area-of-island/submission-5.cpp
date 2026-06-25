class Solution {
public:
    vector<vector<int>>visit;
    int m,n;
    int dfs(vector<vector<int>>&grid, int i, int j){
        visit[i][j] = 1;

        int area = 1;

        vector<int> dirs{-1,0,1};

        for(auto x:dirs){
            for(auto y: dirs){
                if(abs(x)==abs(y))continue;
                int newi = i+x;
                int newj = j+y;


                if(newi<0 || newi>=m || newj<0 || newj>=n) continue;
                if(!visit[newi][newj] && grid[newi][newj]){
                    area += dfs(grid,newi,newj);
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visit.resize(m,vector<int>(n));

        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] && !visit[i][j]){
                    ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};
