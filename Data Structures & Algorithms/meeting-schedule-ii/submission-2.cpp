/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& ints) {
        //use a priority heap
        // track the max size of the heap at any point of time
        vector<vector<int>> intervals;
        for(auto it:ints){
            intervals.push_back({it.start,it.end});
        }
        priority_queue<int,vector<int>,greater<int>> pq;

        int res = 0, n = intervals.size();
        sort(intervals.begin(),intervals.end());
        

        for(int i = 0;i<n;i++){
            int start = intervals[i][0], end = intervals[i][1];
            
            if(!pq.empty() && start>=pq.top()){
                pq.pop();    
            }
            pq.push(end);
        }
        
        return pq.size();
    }
};
