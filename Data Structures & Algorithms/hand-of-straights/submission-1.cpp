class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n% groupSize!=0) return false;

        sort(hand.begin(),hand.end());

        int minnum = hand[0];
        int maxnum = hand[n-1];

        unordered_map<int,int> mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int num = hand[i];

            int numcnt = mpp[num];
            if(numcnt==0) continue;

            for(int j = num;j<num+groupSize;j++){
                if(mpp.find(j)==mpp.end() || mpp[j]<numcnt) return false;
                mpp[j]-=numcnt;
            }

        }
        return true;
        
    }
};
