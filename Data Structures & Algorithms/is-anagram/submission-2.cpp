class Solution {
public:
    string convert(string &s){
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        string keys;
        for(int i = 0;i<26;i++){
            char c= 'a'+i;
            if(mpp.find(c)!=mpp.end()) keys+=c+to_string(mpp[c]);
        }
        return keys;

    }
    bool isAnagram(string s, string t) {
       return convert(s)==convert(t);
    }
};
