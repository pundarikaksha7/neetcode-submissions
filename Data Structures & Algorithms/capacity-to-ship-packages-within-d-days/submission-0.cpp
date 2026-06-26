class Solution {
public:
    bool good(vector<int>&w,int days,int capacity){
        int time  = 1;
        int holder = 0;
        for(int i = 0;i<w.size();i++){
            int wt = w[i];
            if(holder+wt<=capacity){
                holder+=wt;
            }
            else{
                holder = wt;
                time++;
            }
        }
        return time<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, r = 0, n = weights.size();
        for(auto c:weights){
            l = max(l,c);
            r+=c;
        }

        while(l<=r){
            int mid = l+(r-l)/2;

            if(good(weights,days,mid)){
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};