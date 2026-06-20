class Solution {
public:
    int f(vector<vector<int>>&matrix, vector<vector<int>>&dp, int i, int j){

        int m = matrix.size(), n = matrix[0].size();

        vector<int> dirs{-1,0,1};

        int maxpath = 1;

        if(dp[i][j]!=-1) return dp[i][j];

        for(auto x:dirs){
            for(auto y:dirs){
                if(abs(x)==abs(y)) continue;
                int newi = i+x;
                int newj = j+y;

                if(newi<0 || newi>=m || newj<0 || newj>=n) continue;
                if(matrix[newi][newj]>matrix[i][j]){
                    cout<<"going: "<<matrix[newi][newj]<<" ";
                    maxpath = max(maxpath,1+f(matrix,dp,newi,newj));
                }
            }
        }
        return dp[i][j] = maxpath;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        int maxi = 1;
        int elem = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(dp[i][j]==-1){ 
                    int cnt = 0;
                    maxi = max(maxi,cnt = f(matrix,dp,i,j));
                    cout<<matrix[i][j]<<"value:  "<<cnt<<endl;
                }
                else maxi = max(maxi,dp[i][j]);
            }
        }
        // cout<<f(matrix,dp,2,1)<<endl;
        return maxi;
        
    }
};
