class TimeMap {
public:
    map<string,vector<pair<int,string>>> mpp;
    int bs(vector<pair<int,string>>&vec, int num){
        int left=0;
        int right=vec.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(vec[mid].first>num){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(right>=vec.size() || right<0) return -1;
        return right;
    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
        // sort(mpp.begin(),mpp.end());
        
    }
    
    string get(string key, int timestamp) {
        int index=bs(mpp[key],timestamp);
        if(index==-1) return "";
        return mpp[key][index].second;
        
    }
};
