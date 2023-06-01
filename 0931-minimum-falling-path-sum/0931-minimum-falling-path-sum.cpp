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
        
        int directly_below      = dfs(grid,r+1,c,dp);
        int diagonally_left     = dfs(grid,r+1,c-1,dp); 
        int diagonally_right    = dfs(grid,r+1,c+1,dp);
        
        return dp[r][c]=grid[r][c]+min(directly_below,min(diagonally_left,diagonally_right));
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
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1));
        /*
         ==> fill up the base cases
         ==> from the bases start building the solution to the sub problems
         
         
         ==>Base Cases :
            dp[0][...j]=matrix[0][...j]
            
         ==>Building Solution :   
            we need to store the min of three  recurring solutions like below
        int directly_below      = dfs(grid,r+1,c,dp);
        int diagonally_left     = dfs(grid,r+1,c-1,dp); 
        int diagonally_right    = dfs(grid,r+1,c+1,dp);
        */
        for(int i=0;i<cols;i++)
        {
            dp[0][i]=grid[0][i];
        }
        
        for(auto i=1;i<rows;i++)
        {
            for(auto j=0;j<cols;j++)
            {
                int directly_below      = grid[i][j]+dp[i-1][j];
                int diagonally_left     = grid[i][j]; 
                int diagonally_right    = grid[i][j];
                
                //left
                if(j-1>=0)
                {
                    diagonally_left +=dp[i-1][j-1];
                }
                else
                {
                    diagonally_left =INT_MAX;   
                }
                //right
                if(j+1<rows)
                {
                    diagonally_right +=dp[i-1][j+1];
                }
                else
                {
                    diagonally_right =INT_MAX;
                }
                dp[i][j]=min(directly_below,min(diagonally_left,diagonally_right));
            }
        }
        int ans=INT_MAX;
        for(auto i=0;i<cols;i++)
        {
            ans=min(ans,dp[rows-1][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // return memoization(matrix);
        return tabulation(matrix);
    }
};