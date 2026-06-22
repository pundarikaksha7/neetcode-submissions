class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = 0, r = 0, n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        while(l<n){
            int start = intervals[l][0];
            int end = intervals[l][1];

            while(r<n && ((end>=intervals[r][0] && end<=intervals[r][1] )|| end>=intervals[r][1])){
                start = min(start,intervals[r][0]);
                end = max(end,intervals[r][1]);
                r++;
            }

            ans.push_back({start,end});
            l=r;

        }
        return ans;
    }
};
