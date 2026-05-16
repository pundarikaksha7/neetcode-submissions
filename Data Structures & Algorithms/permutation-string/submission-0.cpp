class Solution {
public:
    bool found(unordered_map<char,int>& m1, unordered_map<char,int>& m2) {
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (m1[c] != m2[c]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        unordered_map<char,int> m1, m2;

        for (char c : s1) m1[c]++;

        int l = 0;

        for (int r = 0; r < m; r++) {

            m2[s2[r]]++; // always add right

            if (r - l + 1 > n) { 
                m2[s2[l]]--; // shrink
                l++;
            }

            if (r - l + 1 == n && found(m1, m2))
                return true;
        }
        return false;
    }
};
