class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int n = gas.size();
        for(int i = 0;i<n;i++){
            total+=gas[i]-cost[i];
        }
        if(total<0) return -1;

        int totalgas = 0;
        int index = 0;

        for(int i = 0;i<n;i++){
            totalgas+=gas[i]-cost[i];
            if(totalgas<0){
                totalgas = 0;
                index = i+1;
            }
        }
        return index;

        
    }
};
