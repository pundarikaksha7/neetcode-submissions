class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& target) {
        int n = intervals.size();
        vector<vector<int>> ans;
        bool merged = 0;

        for(int i = 0;i<n;i++){
            int low = intervals[i][0];
            int high = intervals[i][1];

            if(target[0]>=low && target[0]<=high || target[1]<=high &&
            target[1]>=low || low>target[0] && high<target[1]){
                merged = 1;
                low = min(low,target[0]);
                high = max(high, target[1]);
                while(i<n && high>=intervals[i][0]){
                    high = max(high,intervals[i][1]);
                    i++;
                }
                i--;
            }
            ans.push_back({low,high});
        }
        if(!merged){
            intervals.push_back(target);
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        return ans;
    }
};
