#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    set<pair<int,int>> s;
    int n = 0;
    int m = 0;

    bool backtrack(int i , int j, int idx, string word, vector<vector<char>>& board) {
       // cout << "[backtrack] idx=" << idx << ", target char='" << word[idx] 
         //    << "', position=(" << i << "," << j << ")\n";

        if (idx == word.length()) {
         //   cout << "  -> Word matched completely!\n";
            return true;
        }

        if (i < 0 || j < 0 || i >= n || j >= m) {
          //  cout << "  -> Out of bounds (" << i << "," << j << ")\n";
            return false;
        }
        if (s.find({i,j}) != s.end()) {
         //   cout << "  -> Already visited (" << i << "," << j << ")\n";
            return false;
        }
        if (board[i][j] != word[idx]) {
         //  cout << "  -> Mismatch at (" << i << "," << j << "), board=" << board[i][j] 
           //      << ", expected=" << word[idx] << "\n";
            return false;
        }

       // cout << "  -> Visiting (" << i << "," << j << "), char=" << board[i][j] << "\n";
        s.insert({i,j});

        bool ans = backtrack(i+1, j, idx+1, word, board) ||
                   backtrack(i-1, j, idx+1, word, board) ||
                   backtrack(i, j+1, idx+1, word, board) ||
                   backtrack(i, j-1, idx+1, word, board);

        s.erase({i,j});
       // cout << "  -> Backtracking from (" << i << "," << j << ")\n";

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
       // cout << "[exist] Searching for word=\"" << word << "\" in board of size " 
          //   << n << "x" << m << "\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
             //   cout << "[exist] Starting search at (" << i << "," << j << ")\n";
                if (backtrack(i, j, 0, word, board)) {
                    cout << "[exist] Word found!\n";
                    return true;
                }
            }
        }
        //cout << "[exist] Word not found.\n";
        return false;
    }
};
