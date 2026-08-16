class TrieNode {
    public:
    TrieNode *children[26];
    bool isWord;
    TrieNode(){
        for(int i = 0;i<26;i++){
            children[i]=nullptr;
        }
        isWord = false;
    }
};

class PrefixTree {
public:
TrieNode *prefix;
    PrefixTree() {
        prefix  = new TrieNode();
    }
    
    void insert(string word) {

        TrieNode *current = prefix;

        for(auto ch:word){

            int idx = ch-'a';
            if(!current->children[idx]){
                current->children[idx] = new TrieNode();
                
            }
            current = current->children[idx];
        }
        current->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *current = prefix;
        for(auto ch:word){

            int idx = ch-'a';
            if(!current->children[idx]){
                return false;
            }else{
                current = current->children[idx];
            }
        }
        if(current->isWord){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string pre) {
        TrieNode *current = prefix;
        for(auto ch:pre){

            int idx = ch-'a';
            if(!current->children[idx]){
                return false;
            }else{
                current = current->children[idx];
            }
        }
        
        return true;


        
    }
};
