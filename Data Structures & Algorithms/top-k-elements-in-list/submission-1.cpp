class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp; //num,occurences
        for(auto c:nums){
            mpp[c]++;
        }
        vector<vector<int>> freq(nums.size()+1);

        for(auto c:mpp){
            freq[c.second].push_back(c.first);
        }
        vector<int> ans;
        for(int i=freq.size()-1;i>=0;i--){
            for(auto c:freq[i]){
                ans.push_back(c);
                if(ans.size()==k)return ans;
            }
        }
        return {};
        
    }
};
