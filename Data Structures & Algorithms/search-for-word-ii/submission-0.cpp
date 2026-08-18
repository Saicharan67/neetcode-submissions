#include <vector>
#include <string>
#include <set>
using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    bool isWord;
    int index;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
        index = -1;
    }
};

class Solution {
public:
    TrieNode *prefix;
    vector<string> res;
    vector<string> word;

    void insert(string w, int idx) {
        TrieNode *current = prefix;
        for (auto ch : w) {
            int pos = ch - 'a';   // renamed to avoid shadowing
            if (!current->children[pos]) {
                current->children[pos] = new TrieNode();
            }
            current = current->children[pos];
        }
        current->isWord = true;
        current->index = idx;
    }
    
    set<pair<int,int>> s;
    int n = 0;
    int m = 0;

    bool backtrack(int i, int j, TrieNode *current, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        if (s.find({i, j}) != s.end()) return false;

        char ch = board[i][j];
        if (!current->children[ch - 'a']) return false;

        current = current->children[ch - 'a'];

        // found a word
        if (current->isWord) {
            res.push_back(word[current->index]);
            current->isWord = false; // avoid duplicates
        }

        s.insert({i, j});

        backtrack(i + 1, j, current, board);
        backtrack(i - 1, j, current, board);
        backtrack(i, j + 1, current, board);
        backtrack(i, j - 1, current, board);

        s.erase({i, j});
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       prefix = new TrieNode();
        word = words;

        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }

        n = board.size();
        m = board[0].size();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (prefix->children[board[r][c] - 'a']) {
                    backtrack(r, c, prefix, board);
                }
            }
        }

        return res;
    }
};
