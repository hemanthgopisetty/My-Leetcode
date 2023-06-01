class Solution {
public:
    int dfs(vector<vector<int>>&grid,int r,int c,vector<vector<int>>&dp)
    {
        if(r==grid.size()-1 and c<grid[0].size() and c>=0 ) 
        {
            //return first row element 
            //as we traverse from the top down
            
            return grid[r][c];
        }
        
        if(c<0 or c>=grid[0].size())
        {
            return INT_MAX;
        }
        
        if(dp[r][c]!=INT_MAX)return dp[r][c];
        
        // int directly_below      = dfs(grid,r+1,c,dp);
        // int diagonally_left     = dfs(grid,r+1,c-1,dp); 
        // int diagonally_right    = dfs(grid,r+1,c+1,dp);
        
        return dp[r][c]=grid[r][c]+min(dfs(grid,r+1,c,dp),min(dfs(grid,r+1,c-1,dp),dfs(grid,r+1,c+1,dp)));
    }
    int memoization(vector<vector<int>>&grid)
    {
        //we need to traverse all the possiblities from the first row itself
        //so possibulities of 0,0 0,1 0,2 0,3 ..... 0,n
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,INT_MAX));
        int ans=INT_MAX;
        for(int c=0;c<cols;c++)
        {
            ans = min(ans,dfs(grid,0,c,dp));
        }
        return ans;
    }
    int tabulation(vector<vector<int>>&grid)
    {
        return 0;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return memoization(matrix);
    }
};