class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v(n+1);

        unordered_map<int,int> mpp;

        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            int num = it.first;
            int occurences = it.second;

            v[occurences].push_back(num);
        }
        vector<int> ans;
        for(int i = n;i>=1;i--){
            
            for(auto it:v[i]){
                
                ans.push_back(it);
                k--;
                if(k==0) break;
            }
            if(k==0)break;
        }
        return ans;




        
    }
};
