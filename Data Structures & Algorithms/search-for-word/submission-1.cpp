class Solution {
public:
    bool f(vector<vector<char>>& board,
           vector<vector<int>>& seen,
           string& word,
           string curr,
           int i, int j) {

        int m = board.size(), n = board[0].size();

        curr += board[i][j];

        if(curr == word) return true;

        // prefix pruning
        if(curr.back() != word[curr.size()-1])
            return false;

        seen[i][j] = 1;

        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        for(auto [dx, dy] : dir) {

            int ni = i + dx;
            int nj = j + dy;

            if(ni >= 0 && ni < m &&
               nj >= 0 && nj < n &&
               !seen[ni][nj]) {

                if(f(board, seen, word, curr, ni, nj))
                    return true;
            }
        }

        seen[i][j] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size(), n = board[0].size();

        vector<vector<int>> seen(m, vector<int>(n,0));

        string curr = "";

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(f(board, seen, word, curr, i, j))
                    return true;
            }
        }

        return false;
    }
};