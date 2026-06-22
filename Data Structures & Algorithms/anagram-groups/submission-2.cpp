class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(auto it:strs){
            unordered_map<char,int> count;
            for(auto c:it){
                count[c]++;
            }
            string key;
            for(int i = 0;i<26;i++){
                char c = 'a'+i;
                if(count.find(c)!=count.end()){
                    key+=c+to_string(count[c]);
                }
            }
            mpp[key].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
