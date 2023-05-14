class Solution {
public:
    int dp[1001][1001];
    int dfs(vector<vector<int>>& grid,int c,int r,int prev)
    {
        if(r>=grid[0].size() or c<0 or c>=grid.size() or grid[c][r]<=prev) return -1;
        
        if(dp[c][r]!=-1)return dp[c][r];
        
        int x=1+dfs(grid,c-1,r+1,grid[c][r]);
        int y=1+dfs(grid,c,r+1,grid[c][r]);
        int z=1+dfs(grid,c+1,r+1,grid[c][r]);
        
        return dp[c][r] = max(x,max(y,z));
    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(auto i=0;i<grid.size();i++)
        {
            ans=max(ans,dfs(grid,i,0,-1));
        }
        return ans ;
    }
};