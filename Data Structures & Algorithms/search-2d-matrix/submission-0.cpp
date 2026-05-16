class Solution {
public:

    int bs(vector<int> &mat,int &target){
        int left=0;
        int right=mat.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(mat[mid]==target) return 1;
            if(mat[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        if(target<mat[0]) return -1;
        else if(target>mat.back()) return 2;
        cout<<"nf";
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left,top,right,bottom;
        int m=matrix.size();
        int n=matrix[0].size();

        left=0,top=0;
        bottom=m-1,right=n-1;

        while(top<=bottom){
            int mid=top+(bottom-top)/2;

            if(bs(matrix[mid],target)==1 || bs(matrix[mid],target)==0) return bs(matrix[mid],target);
            if(bs(matrix[mid],target)==-1){
                bottom=mid-1;
            }
            else{
                top=mid+1;
            }
        }
        cout<<"done";
        return 0;
    
        
    }
};
