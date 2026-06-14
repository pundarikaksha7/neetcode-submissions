class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> startindex(26,-1);
        vector<int> endindex(26,-1);
        int n = s.length();

        for(int i = 0;i<n;i++){
            int ind = s[i]-'a';
            cout<<ind<<" ";
            if(startindex[ind]==-1){
                startindex[ind] = i;
            }
            
        }
        for(int i = n-1;i>=0;i--){
            int ind = s[i]-'a';
            if(endindex[ind]==-1){
                endindex[ind] = i;
            }
        }

        vector<pair<int,int>> ranges;
        for(int i = 0;i<26;i++){
            int start = startindex[i];
            int end = endindex[i];
            if(start == -1 || end == -1)continue;

            ranges.push_back({start,end});
        }   
        sort(ranges.begin(),ranges.end());

        int l = 0, r = 0;
        vector<int> ans;

        while(l<ranges.size() && r<ranges.size()){
            pair<int,int> hold  = ranges[l];
            int rangecnt = 1;
            int low = hold.first;
            int high = hold.second;
            while(r<ranges.size() && ranges[r].first<=high){
                // check = ranges[r];
                if(ranges[r].second>high) high = ranges[r].second;
                rangecnt = max(rangecnt,high-low+1);
                r++;
            }
            ans.push_back(rangecnt);
            l = r;
        }
        return ans;
        
    }
};
