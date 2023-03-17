class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       n=grid.size();
       m=grid[0].size();
       ans=0;
       for(int cl=0;cl<n;cl++){
           for(int cn=0;cn<m;cn++){
               if(grid[cl][cn]==1){
                   int cnt=dfs(grid,cl,cn);
                   ans=max(ans,cnt);
               }
           }
       }
        return ans;
    }
private :
    int n,m,ans;
    int dfs(vector<vector<int>>& grid,int cl,int cn){
        if(cl<0 or cl>=n or cn<0 or cn>=m or grid[cl][cn]==0){
            return 0;
        }
        grid[cl][cn]=0;
        return(1+dfs(grid,cl-1,cn)+dfs(grid,cl+1,cn)+dfs(grid,cl,cn-1)+dfs(grid,cl,cn+1));
    }
};