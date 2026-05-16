class Solution {
public:
    bool traverse(int x,int y,vector<vector<char>>&b){
        unordered_set<char> st;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(b[i][j]=='.')continue;
                if(st.find(b[i][j])!=st.end()){
                    cout<<"box";
                    return false;}
                else{
                    st.insert(b[i][j]);
                }
            }
            
        }
        return true;
        

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;

        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=0;j<n;j++){
                char el=board[i][j];
                if(el=='.')continue;
                if(st.find(el)==st.end()){
                    st.insert(el);
                }
                else{
                    cout<<board[i][j];
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=0;j<n;j++){
                char el=board[j][i];
                if(el=='.')continue;
                if(st.find(el)==st.end()){
                    st.insert(el);
                }
                else{
                    cout<<"col";
                    return false;
                }
            }
        }
        //Row outer loop
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(traverse(i,j,board)==false)return false;
            }
        }
        return true;
        
    }
};
