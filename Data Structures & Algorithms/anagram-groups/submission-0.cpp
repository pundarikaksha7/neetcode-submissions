class Solution {
public:
    // bool isanagram(string a,string b){
    //     if(a.length()!=b.length())return false;

    //     sort(a.begin(),a.end());
    //     sort(b.begin(),b.end());
    //     if(a==b)return true;
    //     return false;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string,vector<string>> mpp;

        for(auto c:strs){
            string dum=c;
            sort(dum.begin(),dum.end());
            if(mpp.find(dum)==mpp.end())mpp.insert({dum,{c}});
            else{
                mpp[dum].push_back(c);
            }
        }
        for(auto c:mpp){
            ans.push_back(c.second);
        }
        return ans;


        
    }
};
