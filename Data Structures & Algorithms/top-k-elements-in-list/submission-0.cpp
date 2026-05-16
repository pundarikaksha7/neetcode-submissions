class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp; //num,occurences
        for(auto c:nums){
            mpp[c]++;
        }
        vector<int>ans;
        vector<pair<int,int>> vec;

        for(auto c:mpp){
            vec.push_back({c.second,c.first});
        }
        sort(vec.begin(),vec.end());
        int i=vec.size()-1;
        while(k--){
            ans.push_back(vec[i].second);
            i--;
        }
        return ans;
        
    }
};
