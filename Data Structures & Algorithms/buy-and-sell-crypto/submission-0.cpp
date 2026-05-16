class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxnext(prices.size());
        int n=prices.size();
        maxnext[n-1]=prices[n-1];
        int maxi=0;
        if(n<2) return 0;
        for(int i=n-2;i>=0;i--){
            maxnext[i]=max(maxnext[i+1],prices[i]);
            maxi=max(maxi,maxnext[i]-prices[i]);
        }
        return maxi;
        
        
    }
};
