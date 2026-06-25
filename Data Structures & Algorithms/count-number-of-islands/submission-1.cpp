class Solution {
public:
    int m,n;
    vector<vector<int>>visit;
    void dfs(vector<vector<char>>&grid, int i,int j){
        visit[i][j] = 1;

        vector<int> dirs{-1,0,1};

        for(auto x:dirs){
            for(auto y:dirs){
                if(abs(x)==abs(y)) continue;

                int newi = i+x, newj = j+y;
                if(newi< 0 || newi>=m || newj<0 || newj>=n || visit[newi][newj])continue;
                if(grid[newi][newj]=='1')dfs(grid,newi,newj);
            }
        }
        return ;


    }
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size(), n = grid[0].size();
        visit.resize(m,vector<int>(n));

        int cnt = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
