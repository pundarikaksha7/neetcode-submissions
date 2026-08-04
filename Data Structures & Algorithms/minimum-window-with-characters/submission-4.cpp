class Solution {
public:
    bool check(unordered_map<char,int> smap,unordered_map<char,int>tmap){
        for(int i = 0;i<=26;i++){
            char c = 'a'+i;
            if(tmap.find(c)!=tmap.end()){
                if(smap.find(c)==smap.end() || tmap[c]>smap[c]) return false;
            }
        }
        for(int i = 0;i<=26;i++){
            char c = 'A'+i;
            if(tmap.find(c)!=tmap.end()){
                if(smap.find(c)==smap.end() || tmap[c]>smap[c]) return false;
            }
        }
        
        return true;
    }


    string minWindow(string s, string t) {
        unordered_map<char,int> smap,tmap;

        for(auto it:t)tmap[it]++;

        int l = 0, n = s.length(), cnt = INT_MAX;
        string ans = "";

        for(int r = 0;r<n;r++){
            char c = s[r];
            smap[c]++;
            while(l<=r && check(smap,tmap)){
                if(r-l+1<cnt){
                    cnt = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                smap[s[l]]--;
                l++;
                
                
            }
        }
        return ans;
    }
};
