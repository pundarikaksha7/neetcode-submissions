class Solution {
public:
    bool good(vector<int>&piles,int h,int rate){
        int time = 0;
        for(auto c:piles){
            if(c<=rate)time++;
            else{
                time+=c/rate;
                if(c%rate!=0) time++;
            }
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=1e9;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(good(piles,h,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
