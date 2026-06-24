class Solution {
public:
    int dist(vector<int>&points){
        int x = points[0], y = points[1];
        return (pow(x,2) + pow(y,2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // implement a min heap which stores the distance 
        int n = points.size();
        priority_queue<vector<int>,vector<vector<int>>> maxheap;
        // unordered_map<int,vector<vector<int>>> mpp;

        for(int i = 0;i<n;i++){
            int dis = dist(points[i]);
            // mpp[dis].push_back()
            maxheap.push({dis,points[i][0],points[i][1]});
            if(maxheap.size()>k) maxheap.pop();
        }
        vector<vector<int>> ans;
        while(!maxheap.empty()){
            int x = maxheap.top()[1],y = maxheap.top()[2];
            ans.push_back({x,y});
            maxheap.pop();
        }
        return ans;


        // -5 -4. -6 -5. 4 6
        // 41. 61    50
    }
};
