class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcolor = image[sr][sc];
        int m = image.size(), n = image[0].size();

        vector<vector<int>> visit(m,vector<int>(n));

        queue<pair<int,int>> q;
        q.push({sr,sc});

        vector<int> dirs{-1,0,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            visit[x][y] = 1;
            image[x][y] = color;
            q.pop();

            for(auto i:dirs){
                for(auto j:dirs){
                    if(abs(i)==abs(j)) continue;

                    int newx = i+x;
                    int newy = j+y;

                    if(newx < 0 || newx>=m || newy<0 || newy>=n || visit[newx][newy])continue;

                    if(image[newx][newy]==startcolor){
                        q.push({newx,newy});
                    }

                }
            }
            

            
        }
        return image;
    }
};