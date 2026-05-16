class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        string place= "place";

        for(auto c:strs){
            s+=c+place;
        }
        return s;

    }

    vector<string> decode(string s) {
        vector<string> v;
        string a="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='p'){
                string check="";
                for(int j=0;j<5;j++){
                    check+=s[j+i];
                }
                if(check=="place"){
                    i+=4;
                    v.push_back(a);
                    a="";
                }
                else{
                    a+=s[i];
                }
            }
            else{
                a+=s[i];
            }
        }
        if(a!=""){
            v.push_back(a);
        }
        return v;
        
    }
};
