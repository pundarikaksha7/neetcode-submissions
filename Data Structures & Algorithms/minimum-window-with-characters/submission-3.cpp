class Solution {
public:
    bool check(unordered_map<char,int> &tmap, unordered_map<char,int> &smap){
        // need to check if smap is still in tmap

        for(int i = 0;i<26;i++){
            char c = 'a'+i;

            if(tmap.find(c)!=tmap.end()){
                if(smap.find(c)==smap.end() || smap[c]<tmap[c]) return false;
            }
        }
        for(int i = 0;i<26;i++){
            char c = 'A'+i;

            if(tmap.find(c)!=tmap.end()){
                if(smap.find(c)==smap.end() || smap[c]<tmap[c]) return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> smap,tmap;

        for(auto it:t) tmap[it]++;

        int m = s.length(), n = t.length();

        int l = 0;
        string ans;
        int mini = m+n;

        for(int r = 0;r<m;r++){
            char c = s[r];
            smap[c]++;

            while(l<=r && check(tmap,smap)){
                if(r-l+1<mini){
                    mini = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
                smap[s[l]]--;
                l++;
            }

        }
        return ans;

        
    }
};
