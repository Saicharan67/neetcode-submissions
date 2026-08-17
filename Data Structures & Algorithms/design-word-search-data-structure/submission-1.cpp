#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *current = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->isWord = true;
    }

    bool searchhelper(string word, TrieNode *root) {
        TrieNode *current = root;
        for (int j = 0; j < word.length(); j++) {
            char ch = word[j];  // ❌ fixed: word.string(1,j) → word[j]
            if (ch == '.') {
                for (int i = 0; i < 26; i++) {
                    if (current->children[i]) {  // ❌ fixed: children[idx] → children[i]
                        if (searchhelper(word.substr(j + 1), current->children[i])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int idx = ch - 'a';  // ❌ fixed: word.string(1,j)-'a' → word[j]-'a'
                if (!current->children[idx]) {
                    return false;
                }
                current = current->children[idx];
            }
        }
        return current->isWord;
    }
    
    bool search(string word) {
        return searchhelper(word, root);
    }
};
