class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ost;

        for(auto i:board){
            ost.push_back(i);
        }
        deque<vector<int>> arr;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(i==0 || j ==0 || i==n-1 || j==m-1){
                    if(ost[i][j]=='O'){
                        arr.push_back({i,j});
                        ost[i][j] = 'X';
                    }
                }
            }
        }
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        while(arr.size()){

            vector<int> p = arr.front();
            arr.pop_front();
            for (auto& dir : directions) {
                int nr = p[0] + dir[0];
                int nc = p[1] + dir[1];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;

               
                if (ost[nr][nc] == 'O'){
                    ost[nr][nc] = 'X';
                    arr.push_back({nr, nc});
                }
                

               
            }

            
        }
         for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                
                    if(ost[i][j]=='O'){
                       
                        board[i][j] = 'X';
                    }
                }
        }

        return;
        

        
    }
};


       