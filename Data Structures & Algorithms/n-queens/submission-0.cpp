class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posD;
    unordered_set<int> negD;
    vector<vector<string>> res;

    void backtrack(int r, int n, vector<string> &board){

        if(r==n){
            res.push_back(board);
            return;
        }

        for(int c = 0; c<n ; c++){

            if(col.count(c)>0|| posD.count(r+c)>0 || negD.count(r-c)>0){
                continue;
            }

            col.insert(c);
            posD.insert(r+c);
            negD.insert(r-c);
            board[r][c]='Q';
            backtrack(r+1,n,board);
            col.erase(c);
            posD.erase(r+c);
            negD.erase(r-c);
            board[r][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n,string(n,'.'));
        backtrack(0,n,board);
        return res;
    }
};
