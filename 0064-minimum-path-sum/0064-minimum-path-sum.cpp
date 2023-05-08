class Solution {
public:
    //one of the best sum
    //First approach buteforce -> traverse all the possibilites in the matrix
    //find the min sum
    //Buteforce gives tle as couz it will take time to compute is
    //2^N ,for given input size ...this is not suitable algorithm
    //We need to make the recursive tree like struucture having one more children
    //in every level of that recursvice tree
    //into Dag that is possibly only one child in the level of stack operatioin push
    
    int f(vector<vector<int>>& memo,vector<vector<int>>& grid,int m,int n)
    {
        if(n<0 or m<0)return INT_MAX;
        else if(n==0 and m==0)return grid[m][n];
        
        if(memo[m][n]!=-1)return memo[m][n];
            
        return memo[m][n]=grid[m][n] + min(f(memo,grid,m-1,n),f(memo,grid,m,n-1));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return f(memo,grid,m-1,n-1);
    }
};