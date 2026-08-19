class Solution {
public:
    set<pair<int,int>> s;
    int n = 0;
    int m = 0;

    bool backtrack(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        if (s.find({i, j}) != s.end()) return false;
        if (board[i][j]=='0') return false;

       
       
        s.insert({i, j});

        backtrack(i + 1, j, board);
        backtrack(i - 1, j, board);
        backtrack(i, j + 1, board);
        backtrack(i, j - 1, board);

       
        return true;
    }

    int numIslands(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();
        int res = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c]=='1' && (s.find({r, c}) == s.end()) && backtrack(r,c,board)) {
                    res+=1;
                }
            }
        }

        return res;
        
    }
};
