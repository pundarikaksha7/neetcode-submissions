class Solution {
public:
    void dj(vector<vector<int>>&grid){
        //i and j are the indices of a 0
        // have to do djisktra assuming this is the source

        queue<pair<int,int>>pq;
        int m = grid.size();
        int n = grid[0].size();
        // node i j, dist

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    pq.push({i,j});
                }
            }
        }

        

        vector<int>dirs{-1,0,1};

        while(!pq.empty()){
            int nodei = pq.front().first;
            int nodej = pq.front().second;

            pq.pop();
            for(auto x:dirs){
                for(auto y:dirs){
                    if(abs(x)==abs(y))continue;
                    int movex = nodei+x;
                    int movey = nodej+y;

                    if(movex < 0 || movey<0 || 
                    movex>=m || movey>=n || grid[movex][movey]!=INT_MAX)
                    continue;
                    int newgrid = grid[movex][movey];

                    grid[movex][movey] = 1+grid[nodei][nodej];
                    pq.push({movex,movey});
                }
            }
            
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        dj(grid);

        
        
    }
};
