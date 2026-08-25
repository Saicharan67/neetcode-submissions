class Solution {
public:
    int n;
    int m;
    void dfs(int i , int j , vector<vector<int>> &grid, int h,vector<vector<int>> heights){

        if(i<0 || j<0 || i>=n || j>=m || heights[i][j]<h || grid[i][j]==1){
            return;
        }
        grid[i][j] = 1;

        dfs(i+1,j,grid,heights[i][j],heights);
        dfs(i-1,j,grid,heights[i][j],heights);
        dfs(i,j+1,grid,heights[i][j],heights);
        dfs(i,j-1,grid,heights[i][j],heights);

        return;



    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));

        for(int i = 0; i<n; i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dfs(i,j,p,heights[i][j],heights);
                }
                if(i==n-1 || j==m-1){
                    dfs(i,j,a,heights[i][j],heights);
                }
            }
        }

        vector<vector<int>> res;

         for(int i = 0; i<n; i++){
            for(int j=0;j<m;j++){

                if(a[i][j] && p[i][j]){
                    res.push_back({i,j});
                }
            }
         }

         return res;


    }
};
