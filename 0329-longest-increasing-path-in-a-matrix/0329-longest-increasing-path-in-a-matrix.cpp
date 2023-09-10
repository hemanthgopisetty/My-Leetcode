class Solution {
public:
    int dp[200][200]{};
    int dfs(vector<vector<int>>& matrix ,int i ,int j,int n,int m,int prev)
    {
    
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=prev)return 0;
        
        if(dp[i][j]) return dp[i][j];
    
      return dp[i][j]  = 1+ max({
           dfs(matrix,i+1,j,n,m,matrix[i][j]),
           dfs(matrix,i-1,j,n,m,matrix[i][j]),
           dfs(matrix,i,j-1,n,m,matrix[i][j]),
           dfs(matrix,i,j+1,n,m,matrix[i][j])
       }) ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //FROM EACH CELL WE CAN MOVE 
        
        int col = matrix[0].size();
        int row = matrix.size();
        int ans = INT_MIN;
        
        for(auto i=0;i<row;i++)
        {
            for(auto j=0;j<col;j++)
            {
                ans = max(ans , dfs(matrix,i,j,row,col,-1));
            }
        }
        return ans ;
        
    }
};