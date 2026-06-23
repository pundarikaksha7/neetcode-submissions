class Solution {
public:
    bool check(unordered_map<char,int> smap,unordered_map<char,int> tmap){
        for(int i = 0;i<26;i++){
            char c = 'a'+i;
            if(smap.find(c)!=smap.end()){
                if(tmap.find(c)==tmap.end() || tmap[c]!=smap[c]) return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        int m = s.length(), n = t.length();

        for(auto it:s) smap[it]++;

        int l = 0;

        for(int r = 0;r<n;r++){
            char c  = t[r];
            tmap[c]++;

            while(r-l+1>m){
                tmap[t[l]]--;
                l++;
            }

            if(check(smap,tmap)) return true;
        }
        return false;
        
    }
};
