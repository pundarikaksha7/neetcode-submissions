class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int maxi=0;
        vector<int> leftlimit(n,-1);
        vector<int> rightlimit(n,n);

        if(n==1) return h[0];

        stack<pair<int,int>> left;
        stack<pair<int,int>> right;

        for(int i=0;i<n;i++){
            while(!left.empty() && left.top().first>=h[i]){
                left.pop();
            }
            if(!left.empty()){
                leftlimit[i]=left.top().second;
            }
            left.push({h[i],i});

        }
        while(!left.empty())left.pop();
        for(int i=n-1;i>=0;i--){
            while(!left.empty() && left.top().first>=h[i]){
                left.pop();
            }
            if(!left.empty()){
                rightlimit[i]=left.top().second;
            }
            left.push({h[i],i});

        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,(rightlimit[i]-leftlimit[i]-1)*h[i]);
        }
        for(auto c:leftlimit)cout<<c<<" ";
        cout<<endl;
        for(auto c:rightlimit)cout<<c<<" ";
        return maxi;
        

        
    }
};
