class Solution {
public:
    bool good(vector<int>&piles,int h,int k){
        int n = piles.size();
        int hourstaken = 0;
        for(int i = 0;i<n;i++){
            int bananas = piles[i];
            if(bananas<=k) hourstaken++;
            else hourstaken+=bananas/k + (bool)(bananas%k);
        }
        return hourstaken<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        int mini = INT_MAX;
        for(auto it:piles){maxi = max(maxi,it); mini = min(mini,it);}
        int l = 1, r = maxi, n = piles.size();

        while(l<=r){
            int mid = l+(r-l)/2;

            if(good(piles,h,mid)){
                r=mid-1;
            }
            else l = mid+1;
        }
        return l;
        
    }
};
