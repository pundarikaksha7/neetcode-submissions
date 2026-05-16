class Solution {
public:
    bool condition(char a){
        if(a>=48 && a<=57) return true;
        if(a>=65 && a<=90) return true;
        if(a>=97 && a<=122)return true;
        return false;

    }
    bool isPalindrome(string s) {
        string t;
        for(auto c:s){
            c=tolower(c);
            if(condition(c))t+=c;
        }
        s=t;
        int l=0;
        int r=s.length()-1;
        cout<<s;

        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }

        return true;
        
    }
};
