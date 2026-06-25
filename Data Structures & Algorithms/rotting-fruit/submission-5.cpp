class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        bool rotten = false;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        vector<int> dirs{-1,0,1};
        int time = 0;

        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int timeyet = q.front()[2];
            time = max(timeyet,time);

            q.pop();

            for(auto i:dirs){
                for(auto j:dirs){
                    if(abs(i)==abs(j)) continue;
                    int newx = i+x;
                    int newy = j+y;

                    if(newx< 0 || newx>=m || newy<0 || newy>=n) continue;
                    if(grid[newx][newy]==1){
                        grid[newx][newy] = 2;
                        q.push({newx,newy,timeyet+1});
                    }


                }
            }
            
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    rotten = 1;
                    
                }
            }
        }
        return rotten==1?-1:time;
    }
};
