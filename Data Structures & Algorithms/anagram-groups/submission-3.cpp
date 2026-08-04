class Solution {
public:

    string convert(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mpp;

        for(auto s:strs){
            string key = convert(s);
            mpp[key].push_back(s);
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};
