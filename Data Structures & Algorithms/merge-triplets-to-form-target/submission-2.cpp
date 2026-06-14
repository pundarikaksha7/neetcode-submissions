class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        set<int> st;
        for(auto it:triplets){
            int pass = 0;
            for(int i = 0;i<3;i++){
                if(it[i]>target[i]) pass = 1;
            }
            if(pass) continue;

            for(int i = 0;i<3;i++){
                if(it[i]==target[i])st.insert(i);
            }
        }
        return st.size()>=3;
    }
};
