class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>>atlantic(m,vector<int>(n));
        vector<vector<int>>pacific(m,vector<int>(n));

        for(int i = 0;i<m;i++){
            pacific[i][0] = 1;
            atlantic[i][n-1]=1;
        }
        for(int j = 0;j<n;j++){
            pacific[0][j] = 1;
            atlantic[m-1][j] = 1;
        }
        //pacific first

        queue<pair<int,int>> q;
        for(int i = 0;i<m ;i++){
            for(int j = 0;j<n;j++){
                if(pacific[i][j])q.push({i,j});
            }
        }
        vector<int> dirs{-1,0,1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(auto x:dirs){
                for(auto y:dirs){
                    if(abs(x)==abs(y))continue;
                    int movex = i+x;
                    int movey = j+y;

                    if(movex<0 || movey<0 || movex>=m || movey>=n)continue;
                    if(heights[movex][movey]>=heights[i][j] &&
                    pacific[movex][movey]==0){
                        pacific[movex][movey] = 1;
                        q.push({movex,movey});
                    }
                }
            }
        }
        //atlantic
        while(!q.empty())q.pop();
        for(int i = 0;i<m ;i++){
            for(int j = 0;j<n;j++){
                if(atlantic[i][j])q.push({i,j});
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for(auto x:dirs){
                for(auto y:dirs){
                    if(abs(x)==abs(y))continue;
                    int movex = i+x;
                    int movey = j+y;

                    if(movex<0 || movey<0 || movex>=m || movey>=n)continue;
                    if(heights[movex][movey]>=heights[i][j] &&
                    atlantic[movex][movey]==0){
                        atlantic[movex][movey] = 1;
                        q.push({movex,movey});
                    }
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])ans.push_back({i,j});
            }
        }
        return ans;

        

    }
};
