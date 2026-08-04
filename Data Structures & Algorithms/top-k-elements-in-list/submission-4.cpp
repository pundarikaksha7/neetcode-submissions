class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int num = nums[i];

            cnt[num]++;
        }

        //unordered map ready with nums and their counts
        vector<vector<int>> storage(n+1);

        for(auto it:cnt){
            int num = it.first;
            int count = it.second;
            storage[count].push_back(num);
        }

        // 1 2 3
        // 0 7,4

        vector<int> ans;
        int iter = n;

        while(iter>=0){
            for(auto it:storage[iter]){
                ans.push_back(it);
                k--;
                if(k==0)  break;
            }
            if(k==0)  break;
            iter--;
        }
        return ans;

        
        
    }
};
