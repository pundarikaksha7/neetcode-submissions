class Solution {
public:
    int f (vector<int>&coins, int amount, int i){
        int n = coins.size();
        if(amount == 0) return 0;
        if(i==n) return INT_MAX;
        
        

        int mini = INT_MAX;
        

        for(int j = i ;j<n;j++){
            int num = INT_MAX;
            int coin = coins[j];
            if(amount-coin>=0) num = f(coins,amount-coin,j);
            if(num!=INT_MAX) num++;
            mini = min(mini,num);
        }

        return mini;
        //10 5 1.  12

    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = f(coins,amount,0);
        return ans==INT_MAX?-1:ans;
        
    }
};
