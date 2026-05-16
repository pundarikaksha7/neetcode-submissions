class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>&A=nums1;
        vector<int>&B=nums2;
      
        
        if(A.size()>B.size())swap(A,B);
        
        int m=A.size(),n=B.size(); 
        int left=0,right=m;
                int total=m+n;
                int half=(total+1)/2;


        while(true){
            int i=left+(right-left)/2;
            int j = half - i;

            int aleft = i>0?A[i-1]:INT_MIN;
            int bleft= j>0?B[j-1]:INT_MIN;
            int aright=i<m?A[i]:INT_MAX;
            int bright=j<n?B[j]:INT_MAX;

            if(aleft<=bright && bleft<=aright){
                if(total%2==0){
                    return (double)(max(aleft,bleft)+min(aright,bright))/2;
                }
                else{
                    return (double)(max(aleft,bleft));
                }
            }
            else if(aleft>bright){
                right=i-1;
            }
            else left=i+1;


        }
        return -1;
    }
};
