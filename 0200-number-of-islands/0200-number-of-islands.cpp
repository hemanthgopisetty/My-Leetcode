class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        for(auto cl=0;cl<n;cl++){
            for(auto cn=0;cn<m;cn++){
                if(grid[cl][cn]=='1'){
                    dfs(grid,cl,cn,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>&grid,int cl,int cn,int n,int m){
        if(cl<0 or cl>=n or cn<0 or cn>=m or grid[cl][cn]=='0'){
            return ;
        }
        grid[cl][cn]='0';
        dfs(grid,cl-1,cn,n,m);
        dfs(grid,cl+1,cn,n,m);
        dfs(grid,cl,cn-1,n,m);
        dfs(grid,cl,cn+1,n,m);
    }
};