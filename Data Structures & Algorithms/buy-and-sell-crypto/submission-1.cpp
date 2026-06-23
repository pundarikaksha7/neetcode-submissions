class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minyet = INT_MAX;
        int res = 0;

        for(int i = 0;i<prices.size();i++){
            minyet = min(minyet,prices[i]);
            res = max(res,prices[i]-minyet);
        }

        return res;
    }
};
