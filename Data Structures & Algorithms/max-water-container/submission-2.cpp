class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();
        int maxarea = 0;

        int l = 0, r = n-1;

        while(l<r){
            int height = min(heights[l],heights[r]);
            int dist = r-l;

            int area = height * dist;
            maxarea = max(maxarea,area);

            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
        
    }
};
