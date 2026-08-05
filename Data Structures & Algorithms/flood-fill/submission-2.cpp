class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int m = image.size(), n = image[0].size();
        int startcolor = image[sr][sc];

        q.push({sr,sc});

        vector<int> dirs{-1,0,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            image[x][y] = color;
            q.pop();

            for(auto i:dirs){
                for(auto j:dirs){
                    if(abs(i)==abs(j)) continue;
                    int newx = x+i;
                    int newy = y+j;

                    if(newx>=m || newx<0 || newy>=n || newy<0 || image[newx][newy]==color) continue;
                    if(image[newx][newy]==startcolor){
                        
                        q.push({newx,newy});
                    }
                }
            }

        }
        return image;
        
    }
};