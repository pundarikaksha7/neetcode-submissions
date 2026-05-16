class Solution {
public:
    string convertVec(string s){
        vector<int> v(26);
        for(auto c:s){
            v[c-'a']++;
        }
        string mpp;
        for(int i=0;i<26;i++){
            mpp+=to_string('a'+i)+','+to_string(v[i]);
        }
        return mpp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(auto c:strs){
            string convert = convertVec(c);
            mpp[convert].push_back(c);
        }
        vector<vector<string>> ans;
        for(auto c:mpp){
            ans.push_back(c.second);
        }
        return ans;

    }
};
