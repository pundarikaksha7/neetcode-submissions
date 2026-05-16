class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();

        vector<int> leftmax(n);
        vector<int> rightmax(n);


        leftmax[0]=h[0];
        rightmax[n-1]=h[n-1];

        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],h[i]);
        }
        for(int j=n-2;j>=0;j--){
            rightmax[j]=max(rightmax[j+1],h[j]);
        }

        int res=0;
        for(int i=0;i<n;i++){
            res+=(min(leftmax[i],rightmax[i])-h[i]);
        }
        return res;


        
    }
};
