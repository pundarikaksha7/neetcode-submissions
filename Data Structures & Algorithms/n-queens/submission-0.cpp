class Solution {
public:
    bool check(vector<string>&board, int x, int y){
        int m = board.size();
        int n =m;
        for(int i = 0;i<m;i++){
            if(board[i][y]=='Q') return false;
        }
        for(int j = 0;j<n;j++){
            if(board[x][j]=='Q') return false;
        }
        //check diagonal up
        int i =x,j=y;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;j--;
        }
        i=x;j=y;
        //check diagonal down
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;j++;
        }
        return true;
    }
    void f(vector<vector<string>>&ans,vector<string>curr,int i,
    int size){
        int m = size,n=size;

        if(i==n){
            ans.push_back(curr);
            return ;
        }

        // grab a row
        string row;

        row = curr[i];

        for(int j = 0;j<n;j++){
            if(check(curr,i,j)){
                curr[i][j] = 'Q';
                f(ans,curr,i+1,size);
                curr[i][j] = '.';
            }
        }

        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string row = "";
        for(int i = 0;i<n;i++)row+='.';
        vector<string> curr(n,row);

        f(ans,curr,0,n);
        return ans;


        
    }
};
