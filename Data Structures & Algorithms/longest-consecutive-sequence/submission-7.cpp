class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        unordered_set<int> st;
        unordered_map<int,int> done;

        for(auto it:nums) st.insert(it);

        for(int i = 0;i<n;i++){
            int num = nums[i];


            int cnt = 0;
            if(done.find(num)!=done.end()) continue;
            while(st.find(num)!=st.end()){
                done[num] = 1;
                cnt++;
                num++;
            }
            maxi = max(maxi,cnt);
        }  
        return maxi;
    }
};
