class TimeMap {
public:
    map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
        // sort(mpp.begin(),mpp.end());
        
    }
    
    string get(string key, int timestamp) {
        string value = "";
        for(auto c:mpp[key]){
            if(c.first>timestamp) break;
            value=c.second;
        }
        return value;
        
    }
};
