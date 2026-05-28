class Solution {
public:
    void dj(vector<vector<int>>&grid){
        //i and j are the indices of a 0
        // have to do djisktra assuming this is the source

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        int m = grid.size();
        int n = grid[0].size();
        // node i j, dist

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                }
            }
        }

        

        vector<int>dirs{-1,0,1};

        while(!pq.empty()){
            int nodei = pq.top().second.first;
            int nodej = pq.top().second.second;
            int dist = pq.top().first;

            pq.pop();
            for(auto x:dirs){
                for(auto y:dirs){
                    if(abs(x)==abs(y))continue;
                    int movex = nodei+x;
                    int movey = nodej+y;

                    if(movex < 0 || movey<0 || 
                    movex>=m || movey>=n) continue;
                    int newgrid = grid[movex][movey];

                    if(newgrid !=-1 && newgrid>1+dist){
                        grid[movex][movey] = 1+dist;
                        pq.push({1+dist,{movex,movey}});
                    }
                }
            }
            
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        dj(grid);

        
        
    }
};
