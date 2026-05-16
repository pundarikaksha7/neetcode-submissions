class Solution {
public:
    int maxArea(vector<int>&h) {
        int n=h.size();
        int l=0;
        int r=n-1;

        int vol=0;
        int maxvol=0;

        while(l<r){
            vol=(r-l)*min(h[l],h[r]);
            maxvol=max(maxvol,vol);

            if(h[l]<h[r]){
                l++;
            }
            else r--;
        }
        return maxvol;
        
    }
};
