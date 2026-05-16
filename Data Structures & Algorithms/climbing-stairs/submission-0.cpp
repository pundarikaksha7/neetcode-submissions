class Solution {
public:
    int f(vector<int>&steps,int n, int i){
        if(i==n) return 1;
        if(i==n-1) return 1;

        if(steps[i]!=0) return steps[i];
        // climb one step from i
        int one = f(steps,n,i+1);

        //climb two steps from i

        int two = f(steps,n,i+2);

        steps[i] = one+two;

        return one+two;
    }
    int climbStairs(int n) {
        vector<int>steps(n);
        return f(steps,n,0);

        
    }
};
