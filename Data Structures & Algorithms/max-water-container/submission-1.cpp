class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;

        int maxvol = 0;

        while(l<r){
            int vol = min(heights[l],heights[r])* (r-l);

            maxvol = max(maxvol,vol);

            if(heights[r]<=heights[l]){
                r--;
            }
            else l++;
        }
        return maxvol;
        
    }
};
