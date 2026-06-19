class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        int len = board.size();

        for(int i=0; i<len;i++){
            unordered_set<int> row;
            unordered_set<int> column;
            unordered_set<int> grid;

            for(int j=0;j<len;j++){

                if(board[i][j]!='.'){
                    if(row.count(board[i][j])>0){
                        return false;}
                    else{
                        row.insert(board[i][j]);}
                }
                if(board[j][i]!='.'){
                    if(column.count(board[j][i])>0){
                        return false;}
                    else{
                        column.insert(board[j][i]);}
                }
                int x = (j/3)+3*(i/3);
                int y = 3*(i%3)+(j%3);
                if(board[x][y]!='.'){
                    if(grid.count(board[x][y])>0){
                        return false;}
                    else{
                        grid.insert(board[x][y]);}
                }

            }
        }
        return true;
        
    }
};
