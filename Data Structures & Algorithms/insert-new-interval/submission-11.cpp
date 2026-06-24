class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& target) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==0){
            ans.push_back(target);
            return ans;
        }

        int l = 0;
        while(l<n && intervals[l][1]<target[0]){
            ans.push_back(intervals[l]);
            l++;
        }
        //left intervals pushed now we need to merge the intervals till 
        // the start is more than newend
        if(l<n && intervals[l][0]<=target[1]){
            int start = min(intervals[l][0],target[0]);
            int end = max(intervals[l][1],target[1]);

            // whether the end lies in another intervals range or encompasses them

            while(l<n && ((end<=intervals[l][1] && end>=intervals[l][0]) ||
            end>=intervals[l][1])){
                start = min(intervals[l][0],start);
                end = max(intervals[l][1],end);
                l++;
            }
            ans.push_back({start,end});
        }
        else{
            ans.push_back(target);
        }

        while(l<n){
            ans.push_back(intervals[l]);
            l++;
        }
        return ans;
    }
};
