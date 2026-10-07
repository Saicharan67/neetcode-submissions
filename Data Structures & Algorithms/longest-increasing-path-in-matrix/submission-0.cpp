class Solution {
public:
    vector<vector<int>> memo;
    int n = 0;
    int m = 0;
    int recurr(int i , int j , int prev, vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=n || j>=m || prev>=matrix[i][j]){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        
        int a = recurr(i+1,j,matrix[i][j],matrix);
        int b =  recurr(i,j+1,matrix[i][j],matrix);
        int c =  recurr(i,j-1,matrix[i][j],matrix);
        int d =  recurr(i-1,j,matrix[i][j],matrix);
        

        return memo[i][j] = 1+max(max(a,b),max(c,d));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));

        int res = 0;

        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){

                res = max(res,recurr(i,j,INT_MIN,matrix));
            }
        }
        return res;
    }
};
