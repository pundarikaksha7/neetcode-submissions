class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1 1
        // 2 2
        // 3 3
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto c:nums){
            mpp[c]++;
        }
        vector<vector<int>> revmpp(nums.size()+1);

        for(auto c:mpp){
            revmpp[c.second].push_back(c.first);
        }

        vector<int> answers;

        for(int i = n;i>=0;i--){
            for(auto c:revmpp[i]){
                if(k==0) break;
                answers.push_back(c);
                k--;
            }
            if(k==0) break;
        } 
        return answers;
        //1 2 2 3 3 3 4 4
        //0 1 2 3 4 5 6 7
        //0 1 {2,4} {3}

        
    }
};
