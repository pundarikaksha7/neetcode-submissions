class Solution {
public:
    void dfs(vector<vector<char>> &board,vector<vector<int>>&notsurr,int i,
    int j){
        int m = board.size(), n = board[0].size();
        if(notsurr[i][j]) return;
        notsurr[i][j]=1;
        vector<int> dirs{-1,0,1};
        for(auto x:dirs){
            for(auto y:dirs){
                if(abs(x)==abs(y)) continue;
                int movex = i+x;
                int movey = j+y;

                if(movex<0 || movey<0 || movex>=m || movey>=n)continue;
                if(board[movex][movey]=='O' && !notsurr[movex][movey]){
                    dfs(board,notsurr,movex,movey);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> notsurr(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            if(board[i][0]=='O' && notsurr[i][0]==0){
                dfs(board,notsurr,i,0);
            }
            if(board[i][n-1]=='O' && notsurr[i][n-1]==0){
                dfs(board,notsurr,i,n-1);
            }

        }
        for(int j = 0;j<n;j++){
            if(board[0][j]=='O' && notsurr[0][j]==0){
                dfs(board,notsurr,0,j);
            }
            if(board[m-1][j]=='O' && notsurr[m-1][j]==0){
                dfs(board,notsurr,m-1,j);
            }

        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(notsurr[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        
    }
};
