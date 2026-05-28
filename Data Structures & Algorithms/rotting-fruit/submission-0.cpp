class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> time(m,vector<int>(n,INT_MAX));

        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    time[i][j]=0;
                }
            }
        }
        vector<int> dirs{-1,0,1};
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int timeyet = q.front().second;

            q.pop();

            for(auto x:dirs){
                for(auto y:dirs){
                    if(abs(x)==abs(y))continue;
                    int newi = i+x;
                    int newj = j+y;
                    if(newi<0 || newj<0 || newi>=m || newj>=n
                    || grid[newi][newj]!=1)continue;

                    if(timeyet + 1<time[newi][newj]){
                        time[newi][newj] = timeyet+1;
                        q.push({{newi,newj},timeyet+1});
                    }
                }
            }
            
        }
        int maxtime = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && time[i][j]==INT_MAX) return -1;
                if(grid[i][j]==1){
                    maxtime = max(maxtime,time[i][j]);
                }
            }
        }
        return maxtime;
    }
};
